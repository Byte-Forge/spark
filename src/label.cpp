#include <spark/label.hpp>
#include <nanovg.h>
#include <iostream>

using namespace spark;

ILabel::ILabel() : m_text(""), m_size(18.f), m_font("arial-sans"), m_font_color(0,0,0,255), IElement()
{
	
}

void ILabel::OnInitialize()
{

}

void ILabel::OnPaint(const PaintEvent& ev,const Dimension& box)
{
	if(m_visible)
	{
		NVGcontext* vg = static_cast<NVGcontext*>(ev.context);
		
		// m_margin, m_padding:
		// x - up
		// y - right
		// z - bottom
		// w -left

		vec2<unsigned int> position(box.box.x + m_margin.w, box.box.y + m_margin.x + m_size*0.5f);
		vec2<unsigned int> text_position(position.x + m_padding.w, position.y + m_padding.x);
	
		m_width = m_text.length() * m_size *0.4 + m_margin.w + m_margin.y;
		m_height = m_size + 1 + m_margin.x + m_margin.z;
		
		vec4<unsigned int> border_box(position.x, position.y - m_size*0.5f, m_width, m_height);

		nvgBeginPath(vg);
		nvgRoundedRect(vg, border_box.x , border_box.y, border_box.z, border_box.w, m_border_radius);
		nvgFillColor(vg, nvgRGBA(m_bg_color.x, m_bg_color.y, m_bg_color.z, m_bg_color.w));
		nvgFill(vg);

		nvgStrokeColor(vg, nvgRGBA(m_border_color.x, m_border_color.y, m_border_color.z, m_border_color.w));
		nvgStrokeWidth(vg, m_border_size);
		nvgStroke(vg);
		
		nvgFontSize(vg, m_size);
		nvgFontFace(vg, m_font.c_str());
		nvgFillColor(vg, nvgRGBA(m_font_color.x, m_font_color.y, m_font_color.z, m_font_color.w));
		
		nvgTextAlign(vg, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
		nvgText(vg, text_position.x, text_position.y, m_text.c_str(), NULL);
	}
}

void ILabel::Update(Mouse mouse)
{

}
