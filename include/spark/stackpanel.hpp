#pragma once
#include <iostream>
#include <unordered_set>
#include <spark/container.hpp>

namespace spark
{
	enum Orientation
	{
		VERTICAL,
		HORIZONTAL,
	};

	class StackPanel : public IContainer
	{ 
	public:
		StackPanel();

		void OnPaint(const PaintEvent& ev, const Dimension& dim);
		void OnInitialize();
		void Update(Mouse mouse);

		void SetOrientation(Orientation o) { m_orientation = o; }

	private:
		void PaintChildren(const PaintEvent& ev, const Dimension& dim);

	private:
		int m_childWidth;
		int m_childHeight;
		Orientation m_orientation;

	};
}