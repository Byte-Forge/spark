#include <spark/checkbox.hpp>
#include <nanovg.h>
#include <iostream>

using namespace spark;

Checkbox::Checkbox() : IElement()
{
	m_bg_color = vec4<unsigned int>(0, 0, 0, 100);
	m_border_radius = 12;
	m_border_color = vec4<unsigned int>(0, 0, 0, 255);
	m_border_size = 2;
}

Checkbox::~Checkbox()
{

}

void Checkbox::OnInitialize()
{

}

void Checkbox::OnPaint(const PaintEvent& ev, const Dimension& box)
{
	if (m_visible)
	{
		NVGcontext* vg = static_cast<NVGcontext*>(ev.context);

		CalcPosition(box);
		//TODO: make square

		nvgBeginPath(vg);
		nvgRoundedRect(vg, m_box.x, m_box.y, m_box.width, m_box.height, m_border_radius);
		nvgFillColor(vg, nvgRGBA(m_bg_color.x, m_bg_color.y, m_bg_color.z, m_bg_color.w));
		nvgFill(vg);

		nvgStrokeColor(vg, nvgRGBA(m_border_color.x, m_border_color.y, m_border_color.z, m_border_color.w));
		nvgStrokeWidth(vg, m_border_size);
		nvgStroke(vg);
	}
}

void Checkbox::Update(Mouse mouse)
{
	if (m_visible)
	{
		MouseOver(mouse);
		m_update(shared_from_this());
	}
}
