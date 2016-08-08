#include <spark/button.hpp>
#include <nanovg.h>
#include <iostream>

using namespace spark;

IButton::IButton() : IElement()
{

}

void IButton::OnInitialize()
{
	
}

void IButton::OnPaint(const PaintEvent& ev, const Dimension& box)
{
	if(m_visible)
	{
		NVGcontext* vg = static_cast<NVGcontext*>(ev.context);

		CalcPosition(box);
		if (m_hovered)
		{
			nvgBeginPath(vg);
			nvgRoundedRect(vg, m_box.x, m_box.y, m_box.width, m_box.height, m_border_radius);
			nvgFillColor(vg, nvgRGBA(m_hovered_bg_color.x, m_hovered_bg_color.y, m_hovered_bg_color.z, m_hovered_bg_color.w));
			nvgFill(vg);

			if (m_hovered_image != nullptr)
			{
				m_hovered_image->OnPaint(ev, m_box);
			}
			if (m_hovered_label != nullptr)
			{
				m_hovered_label->OnPaint(ev, m_box);
			}

			nvgStrokeColor(vg, nvgRGBA(m_hovered_border_color.x, m_hovered_border_color.y, m_hovered_border_color.z, m_hovered_border_color.w));
			nvgStrokeWidth(vg, m_border_size);
			nvgStroke(vg);
		}
		else
		{
			nvgBeginPath(vg);
			nvgRoundedRect(vg, m_box.x, m_box.y, m_box.width, m_box.height, m_border_radius);
			nvgFillColor(vg, nvgRGBA(m_bg_color.x, m_bg_color.y, m_bg_color.z, m_bg_color.w));
			nvgFill(vg);

			if (m_image != nullptr)
			{
				m_image->OnPaint(ev, m_box);
			}
			if (m_label != nullptr)
			{
				m_label->OnPaint(ev, m_box);
			}

			nvgStrokeColor(vg, nvgRGBA(m_border_color.x, m_border_color.y, m_border_color.z, m_border_color.w));
			nvgStrokeWidth(vg, m_border_size);
			nvgStroke(vg);
		}
	}
}

void IButton::Update(Mouse mouse)
{
	if (m_visible)
	{
		MouseOver(mouse);
		m_update(shared_from_this());
		if (m_hovered && mouse.ButtonJustReleased(MouseCode::MOUSE_LEFT))
		{
			m_mouseLeftDown(shared_from_this());
		}
	}
}

void IButton::SetImage(std::shared_ptr<IImage> image)
{
	m_image = image;
	m_image->SetHorizontalAlignment(CENTER);
	m_image->SetVerticalAlignment(CENTER);
}

void IButton::SetHoveredImage(std::shared_ptr<IImage> image)
{
	m_hovered_image = image;
	m_hovered_image->SetHorizontalAlignment(CENTER);
	m_hovered_image->SetVerticalAlignment(CENTER);
}

void IButton::SetLabel(std::shared_ptr<ILabel> label)
{
	m_label = label;
	m_label->SetHorizontalAlignment(CENTER);
	m_label->SetVerticalAlignment(CENTER);
}

void IButton::SetHoveredLabel(std::shared_ptr<ILabel> label)
{
	m_hovered_label = label;
	m_hovered_label->SetHorizontalAlignment(CENTER);
	m_hovered_label->SetVerticalAlignment(CENTER);
}
