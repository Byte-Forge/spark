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

	private:

	};
}