#pragma once
#include <string>
#include "element.hpp"
#include <memory>

namespace spark
{
	class Slider : public IElement
	{
	public:
		Slider(Orientation orientation);

		void OnPaint(const PaintEvent& ev, const Dimension& box);
		void OnInitialize();
		void Update(Mouse mouse, Keyboard keyboard, std::shared_ptr<View> view);

		void SetVisible(const bool visible);

		inline void SetValue(const float value) { m_value = value; }
		inline int GetValue() { return m_value; }
		inline void SetMinValue(const int value) { m_minValue = value; }
		inline void SetMaxValue(const int value) { m_maxValue = value; }

	private:
		float m_value;
		float m_minValue;
		float m_maxValue;
		int m_knobRadius;

		Orientation m_orientation;
		vec4<unsigned int> m_knob_color;
	};
}