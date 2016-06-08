#include <spark/grid.hpp>
#include <nanovg.h>
#include <iostream>
using namespace spark;

void Grid::OnInitialize()
{
	std::cout << "Initialized grid" << std::endl;
}

void Grid::OnPaint(const PaintEvent& ev, const Dimension& dim)
{
	//Draw the grid background etc.
	NVGcontext* vg = static_cast<NVGcontext*>(ev.context);
	nvgRect(vg, dim.box.x, dim.box.y, dim.box.z, dim.box.w);
	nvgFillColor(vg,nvgRGBA(m_bg_color.x,m_bg_color.y,m_bg_color.z,m_bg_color.w));
	PaintChildren(ev,dim);
}

void Grid::PaintChildren(const PaintEvent& ev, const Dimension& dim)
{

	for (const auto& child : m_children)
	{
		//Calculate dimensions from margin and padding
		
		child->OnPaint(ev, dim);
	}
}