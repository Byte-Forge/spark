#include <spark/label.hpp>
#include <nanovg.h>
#include <iostream>

using namespace spark;

ILabel::ILabel() : m_text(""), m_size(18.f), m_font("arial-sans")
{
	
}

void ILabel::OnInitialize()
{
	std::cout << "Initialized label" << std::endl;
}

void ILabel::OnPaint(const PaintEvent& ev,const Dimension& box)
{
	if(m_visible)
	{
		NVGcontext* vg = static_cast<NVGcontext*>(ev.context);
		
		nvgFontSize(vg, m_size);
		nvgFontFace(vg, m_font.c_str());
		nvgFillColor(vg, nvgRGBA(0,0,0,255));

		vec2<unsigned int> position(box.box.x + m_margin.x + m_padding.x, box.box.y + m_margin.y + m_padding.y + m_size*0.5f);

		nvgTextAlign(vg, NVG_ALIGN_LEFT|NVG_ALIGN_MIDDLE);
		nvgText(vg, position.x, position.y, m_text.c_str(), NULL);
	}
}
