#include <spark/image.hpp>
#include <nanovg.h>
#include <iostream>

using namespace spark;

IImage::IImage(const std::string& file) : m_file(file), IElement()
{
	m_bg_color = vec4<unsigned int>(0, 0, 0, 0);
}

IImage::~IImage()
{
	//delete the image
}

void IImage::OnInitialize()
{
	std::cout << "Initialized image" << std::endl;
}

void IImage::OnPaint(const PaintEvent& ev, const Dimension& box)
{
	if(m_visible)
	{
		NVGcontext* vg = static_cast<NVGcontext*>(ev.context);

		vec2<unsigned int> position(box.box.x + m_margin.w, box.box.y + m_margin.x);
		vec4<unsigned int> border_box(position.x, position.y, m_width, m_height);

		nvgBeginPath(vg);
		nvgRect(vg, border_box.x, border_box.y, border_box.z, border_box.w);
		nvgFillColor(vg, nvgRGBA(m_bg_color.x, m_bg_color.y, m_bg_color.z, m_bg_color.w));

		if (m_image == -1)
		{
			m_image = nvgCreateImage(vg, m_file.c_str(), 0); 
		}

		float alpha = 1.0f;
		NVGpaint imgPaint = nvgImagePattern(vg, border_box.x, border_box.y, m_width, m_height, 0.0f, m_image, alpha);
		nvgFillPaint(vg, imgPaint);
		nvgFill(vg);
	}
}

void IImage::Update(Mouse mouse)
{

}
