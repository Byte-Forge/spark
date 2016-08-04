#include <spark/label.hpp>
#include <nanovg.h>
#include <iostream>

using namespace spark;

ILabel::ILabel() : m_text(""), m_size(18.f), m_font("arial-sans"), m_font_color(0,0,0,255), IElement()
{
	m_bg_color = vec4<unsigned int> (0,0,0,0);
}

void ILabel::OnInitialize()
{

}

void ILabel::OnPaint(const PaintEvent& ev,const Dimension& box)
{
	if(m_visible)
	{
		NVGcontext* vg = static_cast<NVGcontext*>(ev.context);
		
		m_width = m_text.length() * m_size * 0.4 + m_padding.w + m_padding.y; 
		m_height = m_size + m_padding.x + m_padding.z;

		CalcPosition(box);
		m_position.y += m_size * 0.5f;

		nvgBeginPath(vg);
		nvgRoundedRect(vg, m_box.x , m_box.y, m_box.width, m_box.height, m_border_radius);
		nvgFillColor(vg, nvgRGBA(m_bg_color.x, m_bg_color.y, m_bg_color.z, m_bg_color.w));
		nvgFill(vg);

		nvgStrokeColor(vg, nvgRGBA(m_border_color.x, m_border_color.y, m_border_color.z, m_border_color.w));
		nvgStrokeWidth(vg, m_border_size);
		nvgStroke(vg);
		
		nvgFontSize(vg, m_size);
		nvgFontFace(vg, m_font.c_str());
		nvgFillColor(vg, nvgRGBA(m_font_color.x, m_font_color.y, m_font_color.z, m_font_color.w));

		nvgTextAlign(vg, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
		nvgText(vg, m_position.x, m_position.y, m_text.c_str(), NULL);
	}
}

void ILabel::Update(Mouse mouse)
{
	m_function(shared_from_this());
}
