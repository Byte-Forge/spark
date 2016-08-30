#include <spark/stackpanel.hpp>
#include <spark/core.hpp>
#include <nanovg.h>
#include <iostream>

using namespace spark;

StackPanel::StackPanel() : IContainer(), m_orientation(VERTICAL)
{
	m_horizontalAlignment = TOP;
	m_verticalAlignment = LEFT;
}

void StackPanel::OnInitialize()
{
	for (const auto &child : m_children)
	{
		child->SetVerticalAlignment(STRETCH);
		child->SetHorizontalAlignment(STRETCH);
		child->OnInitialize();
	}
}

void StackPanel::SetVisible(const bool visible)
{
	m_visible = visible;
	if (m_image != nullptr)
		m_image->SetVisible(visible);
	m_x_slider.SetVisible(visible);
	m_y_slider.SetVisible(visible);
	for (const auto& child : m_children)
	{
		child->SetVisible(visible);
	}
}

void StackPanel::OnPaint(const PaintEvent& ev, const Dimension& dim)
{
	NVGcontext* vg = static_cast<NVGcontext*>(ev.context);

	CalcPosition(dim);

	if (m_visible)
	{
		nvgBeginPath(vg);
		nvgRoundedRect(vg, m_box.x, m_box.y, m_box.width, m_box.height, m_border_radius);
		nvgFillColor(vg, nvgRGBA(m_bg_color.x, m_bg_color.y, m_bg_color.z, m_bg_color.w));
		nvgFill(vg);

		nvgStrokeColor(vg, nvgRGBA(m_border_color.x, m_border_color.y, m_border_color.z, m_border_color.w));
		nvgStrokeWidth(vg, m_border_size);
		nvgStroke(vg);

		if (m_image != nullptr)
		{
			m_image->OnPaint(ev, m_box);
		}

		Dimension box = m_box;
		if (m_scroll_x)
		{
			Dimension scrollBox = Dimension(m_box);
			scrollBox.y += m_box.height - m_sliderSize;
			scrollBox.height = m_sliderSize;

			box.height -= m_sliderSize;
			m_x_slider.OnPaint(ev, scrollBox);
		}
		

		nvgScissor(vg, m_box.x, m_box.y, m_box.width, m_box.height);
		PaintChildren(ev, box);
		nvgResetScissor(vg);
	}
}

void StackPanel::Update(Mouse mouse, Keyboard keyboard, std::shared_ptr<View> view)
{
	if (m_visible)
	{
		MouseOver(mouse);
		if (m_children.size() > 0)
		{
			if (m_childs_height > (int)(m_height / m_children.size()))
			{
				m_scroll_y = true;
				m_max_vertical_scroll = -1 * m_children.size() * m_childs_height + m_height;
			}
			if (m_childs_width > (int)(m_width / m_children.size()))
			{
				m_scroll_x = true;
				m_max_horizontal_scroll = (-1 * m_children.size() * m_childs_width) + m_width;
			}
		}

		if (m_hovered && mouse.MouseScrolled())
		{
			if (m_scroll_x)
			{
				m_horizontal_scroll += mouse.GetMouseWheelDelta() * 10;
				if (m_horizontal_scroll > 0)
					m_horizontal_scroll = 0;
				if (m_horizontal_scroll < m_max_horizontal_scroll)
					m_horizontal_scroll = m_max_horizontal_scroll;
				m_x_slider.SetValue(m_horizontal_scroll / (float)m_max_horizontal_scroll * 100.0f);
			}
		}

		Core::GetCore()->ExecuteFunction(shared_from_this(), m_update);
		for (const auto& child : m_children)
		{
			child->Update(mouse, keyboard, view);
		}
	}
}

void StackPanel::PaintChildren(const PaintEvent& ev, const Dimension& dim)
{
	int id = 0;
	for (const auto& child : m_children)
	{
		if (m_orientation == HORIZONTAL)
		{
			if (m_childs_width == 0)
				m_childs_width = (int)dim.width / m_children.size();
			Dimension d = { dim.x + id * m_childs_width + m_horizontal_scroll, dim.y, static_cast<unsigned int> (m_childs_width), dim.height };
			child->OnPaint(ev, d);
			id++;
		}
		else //default VERTICAL
		{
			if (m_childs_height == 0)
				m_childs_height = (int)dim.height / m_children.size();
			Dimension d = { dim.x, dim.y + id * m_childs_height, dim.width, static_cast<unsigned int> (m_childs_height) };
			child->OnPaint(ev, d);
			id++;
		}
	}
}
