#pragma once
#include <spark/container.hpp>

namespace spark
{
	class StackPanel : IContainer
	{
		enum Orientation
		{
			VERTICAL,
			HORIZONTAL,
		};

	public:
		StackPanel();

		virtual void OnPaint(const PaintEvent& ev, const Dimension& dim);
		virtual void OnInitialize();
		virtual void Update(Mouse mouse);

	private:
		virtual void PaintChildren(const PaintEvent& ev, const Dimension& dim);

	private:
		Orientation m_orientation;
	};
}