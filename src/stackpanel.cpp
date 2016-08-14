#include <spark/stackpanel.hpp>
#include <nanovg.h>
#include <iostream>

using namespace spark;

StackPanel::StackPanel() : IContainer()
{
	m_horizontalAlignment = TOP;
	m_verticalAlignment = LEFT;
	m_orientation = VERTICAL;
}

void StackPanel::OnInitialize()
{
	if (m_children.size() == 0)
		return;

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
	for (const auto& child : m_children)
	{
		child->SetVisible(visible);
	}
}


void StackPanel::OnPaint(const PaintEvent& ev, const Dimension& dim)
{
	NVGcontext* vg = static_cast<NVGcontext*>(ev.context);

	CalcPosition(dim);

	if (m_children.size() > 0)
	{
		m_childWidth = (int)(m_width / m_children.size());
		m_childHeight = (int)(m_height / m_children.size());
	}

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

		if (m_children.size() > 0)
			PaintChildren(ev, m_box);
	}
}

void StackPanel::Update(Mouse mouse, Keyboard keyboard)
{
	if (m_visible)
	{
		m_update(shared_from_this());
		for (const auto& child : m_children)
		{
			child->Update(mouse);
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
			Dimension d = { m_box.x + id * m_childWidth, m_box.y, static_cast<unsigned int> (m_childWidth), m_height };
			child->OnPaint(ev, d);
			id++;
		}
		else //default VERTICAL
		{
			Dimension d = { m_box.x, m_box.y + id * m_childHeight, m_box.width, static_cast<unsigned int> (m_childHeight) };
			child->OnPaint(ev, d);
			id++;
		}
	}
}
