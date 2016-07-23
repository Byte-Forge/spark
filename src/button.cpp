#include <spark/button.hpp>
#include <nanovg.h>
#include <iostream>

using namespace spark;

IButton::IButton() : IElement()
{
	
}

IButton::IButton(const std::string imgFile) : IElement()
{
	m_image = std::make_shared<IImage>(imgFile);
}

void IButton::OnInitialize()
{
	if (m_image != nullptr)
	{
		m_image->SetWidth(m_width);
		m_image->SetHeight(m_height);
		m_image->SetMargin(m_margin);
	}
}

void IButton::OnPaint(const PaintEvent& ev, const Dimension& box)
{
	if(m_visible)
	{
		NVGcontext* vg = static_cast<NVGcontext*>(ev.context);

		vec2<unsigned int> position(box.box.x + m_margin.w, box.box.y + m_margin.x);
		m_border_box = vec4<unsigned int>(position.x, position.y, m_width, m_height);
		nvgBeginPath(vg);
		nvgRoundedRect(vg, m_border_box.x, m_border_box.y, m_border_box.z, m_border_box.w, m_border_radius);
		nvgFillColor(vg, nvgRGBA(m_bg_color.x, m_bg_color.y, m_bg_color.z, m_bg_color.w));
		nvgFill(vg);

		if (m_image != nullptr)
			m_image->OnPaint(ev, box);

		nvgStrokeColor(vg, nvgRGBA(m_border_color.x, m_border_color.y, m_border_color.z, m_border_color.w));
		nvgStrokeWidth(vg, m_border_size);
		nvgStroke(vg);
	}
}

//std::function als callback
void IButton::Update(Mouse mouse)
{
	if (m_visible)
	{
		vec2<int> mouse_pos = mouse.GetMousePosition();
		if (mouse_pos.x >= m_border_box.x && mouse_pos.x <= (m_border_box.x + m_border_box.z)
			&& mouse_pos.y >= m_border_box.y && mouse_pos.y <= (m_border_box.y + m_border_box.w)
			&& mouse.ButtonJustReleased(MouseCode::MOUSE_LEFT))
		{
			m_function();
		}
	}
}
