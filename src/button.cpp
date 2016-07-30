#include <spark/button.hpp>
#include <nanovg.h>
#include <iostream>

using namespace spark;

IButton::IButton() : IElement()
{
	
}

void IButton::OnInitialize()
{
	//make sure the border radius is not too big
	int min = (m_width > m_height) ? m_height : m_width;
	if (m_border_radius > min)
		m_border_radius = min;
}

void IButton::OnPaint(const PaintEvent& ev, const Dimension& box)
{
	if(m_visible)
	{
		NVGcontext* vg = static_cast<NVGcontext*>(ev.context);

		CalcPosition(box);

		nvgBeginPath(vg);
		nvgRoundedRect(vg, m_box.box.x, m_box.box.y, m_box.box.z, m_box.box.w, m_border_radius);
		nvgFillColor(vg, nvgRGBA(m_bg_color.x, m_bg_color.y, m_bg_color.z, m_bg_color.w));
		nvgFill(vg);

		if (m_image != nullptr)
		{
			m_image->OnPaint(ev, m_box);
		}

		nvgStrokeColor(vg, nvgRGBA(m_border_color.x, m_border_color.y, m_border_color.z, m_border_color.w));
		nvgStrokeWidth(vg, m_border_size);
		nvgStroke(vg);
	}
}

void IButton::Update(Mouse mouse)
{
	if (m_visible)
	{
		vec2<int> mouse_pos = mouse.GetMousePosition();
		if (mouse_pos.x >= m_box.box.x && mouse_pos.x <= (m_box.box.x + m_box.box.z)
			&& mouse_pos.y >= m_box.box.y && mouse_pos.y <= (m_box.box.y + m_box.box.w)
			&& mouse.ButtonJustReleased(MouseCode::MOUSE_LEFT))
		{
			if (m_border_radius == 0)
				m_function(shared_from_this());

			//test for the 4 rounded corners
			else
			{
				vec2<int> upperLeft = vec2<int>(m_box.box.x + m_border_radius, m_box.box.y + m_border_radius);
				vec2<int> upperRight = vec2<int>(m_box.box.x + m_box.box.z - m_border_radius, m_box.box.y + m_border_radius);
				vec2<int> lowerLeft = vec2<int>(m_box.box.x + m_border_radius, m_box.box.y + m_box.box.w - m_border_radius);
				vec2<int> lowerRight = vec2<int>(m_box.box.x + m_box.box.z - m_border_radius, m_box.box.y + m_box.box.w - m_border_radius);

				if (mouse_pos.x < upperLeft.x && mouse_pos.y < upperLeft.y)
				{
					if (mouse_pos.distance(upperLeft) <= m_border_radius)
					{
						m_function(shared_from_this());
					}
				}
				else if (mouse_pos.x > upperRight.x && mouse_pos.y < upperRight.y)
				{
					if (mouse_pos.distance(upperRight) <= m_border_radius)
					{
						m_function(shared_from_this());
					}
				}
				else if (mouse_pos.x < lowerLeft.x && mouse_pos.y > lowerLeft.y)
				{
					if (mouse_pos.distance(lowerLeft) <= m_border_radius)
					{
						m_function(shared_from_this());
					}
				}
				else if (mouse_pos.x > lowerRight.x && mouse_pos.y > lowerRight.y)
				{
					if (mouse_pos.distance(lowerRight) <= m_border_radius)
					{
						m_function(shared_from_this());
					}
				}
			}
		}
	}
}

void IButton::SetImage(const std::string& imgFile)
{
	m_image = std::make_shared<IImage>();
	m_image->SetImage(imgFile);
}
