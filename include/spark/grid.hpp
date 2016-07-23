#pragma once
#include "container.hpp"

namespace spark
{
	class Grid : public IContainer
	{
	public:
		virtual void OnPaint(const PaintEvent& ev,const Dimension& dim);
		virtual void OnInitialize();
		virtual void Update(Mouse mouse);

	private:
		virtual void PaintChildren(const PaintEvent& ev, const Dimension& dim);
	};
}