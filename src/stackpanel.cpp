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

	m_childWidth = m_width / m_children.size();
	m_childHeight = m_height / m_children.size();
	if (m_orientation == HORIZONTAL)
	{
		int id = 0;
		for (const auto &child : m_children)
		{
			child->SetVerticalAlignment(STRETCH);
			child->SetWidth(m_childWidth);
			child->SetMargin(child->GetMargin() + vec4<unsigned int>(0, m_childWidth * id, 0, 0));
			child->OnInitialize();
			id++;
		}
	}
	else //default VERTICAL
	{
		int id = 0;
		for (const auto &child : m_children)
		{
			child->SetHorizontalAlignment(STRETCH);
			child->SetHeight(m_childHeight);
			child->SetMargin(child->GetMargin() + vec4<unsigned int>(0, 0, m_childHeight * id, 0));
			child->OnInitialize();
			id++;
		}
	}
}

void StackPanel::OnPaint(const PaintEvent& ev, const Dimension& dim)
{
	// TODO: render the child in the order they are added to the panel
	NVGcontext* vg = static_cast<NVGcontext*>(ev.context);

	CalcPosition(dim);

	if (m_visible)
	{
		nvgBeginPath(vg);
		nvgRect(vg, m_box.x, m_box.y, m_box.width, m_box.height);
		nvgFillColor(vg, nvgRGBA(m_bg_color.x, m_bg_color.y, m_bg_color.z, m_bg_color.w));
		nvgFill(vg);

		if (m_image != nullptr)
		{
			m_image->OnPaint(ev, m_box);
		}

		if (m_children.size() > 0)
			PaintChildren(ev, m_box);
	}
}

void StackPanel::Update(Mouse mouse)
{
	for (const auto& child : m_children)
	{
		child->Update(mouse);
	}
}

void StackPanel::PaintChildren(const PaintEvent& ev, const Dimension& dim)
{
	int id = 0;
	for (const auto& child : m_children)
	{
		if (m_orientation == HORIZONTAL)
		{
			Dimension d = { m_box.x + id * m_childWidth, m_box.y, m_box.width, m_box.height };
			child->OnPaint(ev, d);
			id++;
		}
		else //default VERTICAL
		{
			Dimension d = { m_box.x, m_box.y + id * m_childHeight, m_box.width, m_box.height };
			child->OnPaint(ev, d);
			id++;
		}
	}
}
