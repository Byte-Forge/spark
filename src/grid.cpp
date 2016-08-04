#include <spark/grid.hpp>
#include <nanovg.h>
#include <iostream>

using namespace spark;

Grid::Grid() : IContainer()
{

}

void Grid::OnInitialize()
{
	for (auto child : m_children)
		child->OnInitialize();
}

void Grid::OnPaint(const PaintEvent& ev, const Dimension& dim)
{
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

		PaintChildren(ev, m_box);
	}
}

void Grid::Update(Mouse mouse)
{
	for (const auto& child : m_children)
	{
		child->Update(mouse);
	}
}

void Grid::PaintChildren(const PaintEvent& ev, const Dimension& dim)
{
	for (const auto& child : m_children)
	{
		//Calculate dimensions from margin and padding
		
		child->OnPaint(ev, dim);
	}
}
