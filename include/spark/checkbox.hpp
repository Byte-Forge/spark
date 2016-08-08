#pragma once
#include "element.hpp"

namespace spark
{
	class Checkbox : public IElement
	{
	public:
		Checkbox();
		~Checkbox();

		void OnPaint(const PaintEvent& ev, const Dimension& box);
		void OnInitialize();
		void Update(Mouse mouse);

		bool Toggle();
	private:
		bool m_checked;

		vec4<unsigned int> m_checked_border_color;
		vec4<unsigned int> m_checked_bg_color;
	};
}