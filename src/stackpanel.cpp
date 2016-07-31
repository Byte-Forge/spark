#include <spark/stackpanel.hpp>
#include <nanovg.h>

using namespace spark;

StackPanel::StackPanel() : m_orientation(VERTICAL), IContainer()
{

}

void StackPanel::OnInitialize()
{

}

void StackPanel::OnPaint(const PaintEvent& ev, const Dimension& dim)
{
	NVGcontext* vg = static_cast<NVGcontext*>(ev.context);

	CalcPosition(dim);

	if (m_visible)
	{
		nvgBeginPath(vg);
		nvgRect(vg, m_box.x, m_box.y, m_box.width, m_box.height);
		nvgFillColor(vg, nvgRGBA(m_bg_color.x, m_bg_color.y, m_bg_color.z, m_bg_color.w));
		nvgFill(vg);

		//calc the box dimension of a child
		Dimension child_box;
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
	for (const auto& child : m_children)
	{
		child->OnPaint(ev, dim);
	}
}
