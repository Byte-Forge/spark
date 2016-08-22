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
		void Update(Mouse mouse, Keyboard keyboard,std::shared_ptr<View> view);

		void SetVisible(const bool visible);

		void SetOrientation(Orientation o) { m_orientation = o; }

	private:
		void PaintChildren(const PaintEvent& ev, const Dimension& dim);

	private:
		Orientation m_orientation;

	};
}