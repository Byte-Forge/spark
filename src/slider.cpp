#include <spark/slider.hpp>
#include <nanovg.h>
#include <spark/core.hpp>

using namespace spark;

Slider::Slider(Orientation orientation) : IElement(), m_orientation(orientation), m_minValue(0.0f), m_maxValue(100.0f), m_value(0.0f)
{
	m_border_radius = 10;
	m_knobRadius = 0;
}

void Slider::OnInitialize()
{
	if (m_value < m_minValue) m_value = m_minValue;
	if (m_value > m_maxValue) m_value = m_maxValue;
}

void Slider::SetVisible(const bool visible)
{
	m_visible = visible;
}

void Slider::OnPaint(const PaintEvent& ev, const Dimension& box)
{
	if (m_visible)
	{
		NVGcontext* vg = static_cast<NVGcontext*>(ev.context);

		CalcPosition(box);

		nvgBeginPath(vg);
		nvgRoundedRect(vg, m_position.x, m_position.y, m_width, m_height, m_border_radius);
		nvgFillColor(vg, nvgRGBA(m_bg_color.x, m_bg_color.y, m_bg_color.z, m_bg_color.w));
		nvgFill(vg);

		if (m_knobRadius == 0)
		{
			m_knobRadius = m_height / 2.0f;
		}

		vec2<int> knob_position = vec2<int>(m_position.x + m_knobRadius, m_position.y + m_knobRadius);
		float value = (m_value - m_minValue) * ((m_width - m_knobRadius * 2.0f) / 100.0f );

		if (m_orientation == HORIZONTAL)
			knob_position.x += value;
		else
			knob_position.y += value;

		nvgBeginPath(vg);
		nvgCircle(vg, knob_position.x, knob_position.y, m_knobRadius);
		nvgFillColor(vg, nvgRGBA(0, 0, 255, 255));
		nvgFill(vg);

		nvgStrokeColor(vg, nvgRGBA(m_border_color.x, m_border_color.y, m_border_color.z, m_border_color.w));
		nvgStrokeWidth(vg, m_border_size);
		nvgStroke(vg);
	}
}

void Slider::Update(Mouse mouse, Keyboard keyboard, std::shared_ptr<View> view)
{
	if (m_visible)
	{
		Core::GetCore()->ExecuteFunction(shared_from_this(), m_update);

		if (m_hovered && mouse.ButtonPressed(MouseCode::MOUSE_LEFT))
		{
		}
	}
}
