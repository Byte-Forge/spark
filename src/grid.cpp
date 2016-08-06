#include <spark/grid.hpp>
#include <nanovg.h>
#include <iostream>

using namespace spark;

Grid::Grid() : IContainer(), m_rows(1), m_columns(1)
{

}

void Grid::OnInitialize()
{
	for (auto child : m_children)
	{
		child->OnInitialize();
	}
}

void Grid::OnPaint(const PaintEvent& ev, const Dimension& dim)
{
	NVGcontext* vg = static_cast<NVGcontext*>(ev.context);

	CalcPosition(dim);

	m_rowHeight = m_height / m_rows;
	m_columnWidth = m_width / m_columns;

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
		Dimension d = { m_box.x + child->GetGridColumn() * m_columnWidth, m_box.y + child->GetGridRow() * m_rowHeight, m_columnWidth * child->GetColumnSpan(), m_rowHeight * child->GetRowSpan() };
		child->OnPaint(ev, d);
	}
}
