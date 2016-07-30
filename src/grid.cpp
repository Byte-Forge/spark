#include <spark/grid.hpp>
#include <nanovg.h>
#include <iostream>
using namespace spark;

Grid::Grid() : IContainer()
{

}

void Grid::OnInitialize()
{

}

void Grid::OnPaint(const PaintEvent& ev, const Dimension& dim)
{
	NVGcontext* vg = static_cast<NVGcontext*>(ev.context);

	CalcPosition(dim);

	nvgBeginPath(vg);
	nvgRect(vg, m_box.box.x, m_box.box.y, m_box.box.z, m_box.box.w);
	nvgFillColor(vg, nvgRGBA(m_bg_color.x, m_bg_color.y, m_bg_color.z, m_bg_color.w));
	nvgFill(vg); 

	PaintChildren(ev, m_box);
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
