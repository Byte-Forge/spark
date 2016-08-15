#include <spark/label.hpp>
#include <nanovg.h>
#include <vector>
#include "util.hpp"
#include <iostream>

using namespace spark;

Label::Label() : m_text(""), m_size(18.f), m_font("arial-sans"), m_font_color(0,0,0,255), IElement()
{
	m_bg_color = vec4<unsigned int> (0,0,0,0);
}

void Label::OnInitialize()
{

}

void Label::SetVisible(const bool visible)
{
	m_visible = visible;
}

void Label::OnPaint(const PaintEvent& ev,const Dimension& box)
{
	if(m_visible)
	{
		NVGcontext* vg = static_cast<NVGcontext*>(ev.context);
		
		m_width = m_text.length() * m_size * 0.5f + m_padding.w + m_padding.y; 
		m_height = m_size + m_padding.x + m_padding.z;

		CalcPosition(box);
		m_position.y += m_size * 0.5f;

		int num_rows = box.height / m_height;
		std::vector<std::string> text = split(m_text, '\n');
		while (num_rows < text.size())
		{
			text.erase(text.begin());
		}

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
		
		std::string t;
		for (std::string line : text)
		{
			t += line + '\n';
		}

		nvgTextBox(vg, m_position.x, m_position.y, m_box.width, t.c_str(), NULL);
	}
}

void Label::Update(Mouse mouse, Keyboard keyboard,std::shared_ptr<View> view)
{
	if (m_visible)
	{
		m_update(shared_from_this());
	}
}
