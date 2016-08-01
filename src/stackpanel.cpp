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
	if (m_orientation == HORIZONTAL)
	{
		int id = 0;
		int width = m_width / m_children.size();
		for (auto child : m_children)
		{
			child->SetVerticalAlignment(STRETCH);
			child->SetWidth(width);
			child->GetMargin();
			child->SetMargin(child->GetMargin() + vec4<unsigned int>(0, width * id, 0, 0));
			child->OnInitialize();
			id++;
		}
	}
	else //default VERTICAL
	{
		for (auto child : m_children)
		{
			int id = 0;
			int height = m_height / m_children.size();
			for (auto child : m_children)
			{
				child->SetHorizontalAlignment(STRETCH);
				child->SetHeight(height);
				child->OnInitialize();
				id++;
			}
		}
	}
}

void StackPanel::OnPaint(const PaintEvent& ev, const Dimension& dim)
{
	NVGcontext* vg = static_cast<NVGcontext*>(ev.context);

	CalcPosition(dim);

	if (m_visible)
	{
		nvgBeginPath(vg);
		nvgRect(vg, m_box.x, m_box.y, m_box.width, m_box.height);
		nvgFillColor(vg, nvgRGBA(255, m_bg_color.y, m_bg_color.z, 255));
		nvgFill(vg);

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
			int width = m_width / m_children.size();
			Dimension d = { m_box.x + id * width, m_box.y, m_box.width, m_box.height };
			child->OnPaint(ev, d);
			id++;
		}
		else //default VERTICAL
		{
			int height = m_height / m_children.size();
			Dimension d = { m_box.x, m_box.y + id * height, m_box.width, m_box.height };
			child->OnPaint(ev, d);
			id++;
		}
	}
}
