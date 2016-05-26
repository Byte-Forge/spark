#pragma once
#include "container.hpp"

namespace spark
{
	class Grid : public IContainer
	{
	public:
		virtual void OnPaint(const PaintEvent& ev);
		virtual void OnInitialize();
	};
}