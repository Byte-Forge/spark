#pragma once
#include "container.hpp"

namespace spark
{
	class Grid : public IContainer
	{
	public:
		Grid();

		void OnPaint(const PaintEvent& ev,const Dimension& dim);
		void OnInitialize();
		void Update(Mouse mouse);

	private:
		void PaintChildren(const PaintEvent& ev, const Dimension& dim);
	};
}