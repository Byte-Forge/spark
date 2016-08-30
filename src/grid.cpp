#include <spark/grid.hpp>
#include <spark/core.hpp>
#include <nanovg.h>
#include <iostream>

using namespace spark;

Grid::Grid() : IContainer(), m_rows(1), m_columns(1)
{
	m_vertical_scroll = true;
}

void Grid::OnInitialize()
{
	for (auto child : m_children)
	{
		child->OnInitialize();
	}
}

void Grid::SetVisible(const bool visible)
{
	m_visible = visible;
	if (m_image != nullptr)
		m_image->SetVisible(visible);
	for (const auto& child : m_children)
	{
		child->SetVisible(visible);
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

		nvgScissor(vg, m_box.x, m_box.y, m_box.width, m_box.height);
		PaintChildren(ev, m_box);
		nvgResetScissor(vg);
	}
}

void Grid::Update(Mouse mouse, Keyboard keyboard,std::shared_ptr<View> view)
{
	if (m_visible)
	{
		if (m_childs_width * m_children.size() > m_width)
			m_horizontal_scroll = true;
		if (m_childs_height * m_children.size() > m_height)
			m_vertical_scroll = true;

		MouseOver(mouse);
		Core::GetCore()->ExecuteFunction(shared_from_this(), m_update);
		for (const auto& child : m_children)
		{
			child->Update(mouse, keyboard,view);
		}
		if (m_hovered && mouse.ButtonJustReleased(MouseCode::MOUSE_LEFT))
		{
			Core::GetCore()->ExecuteFunction(shared_from_this(), m_onclick);
		}
	}
}

void Grid::PaintChildren(const PaintEvent& ev, const Dimension& dim)
{
	for (const auto& child : m_children)
	{
		Dimension d = { m_box.x + child->GetGridColumn() * m_columnWidth, m_box.y + child->GetGridRow() * m_rowHeight, static_cast<unsigned int>(m_columnWidth * child->GetColumnSpan()), static_cast<unsigned int>(m_rowHeight * child->GetRowSpan()) };
		child->OnPaint(ev, d);
	}
}
