#pragma once
#include "container.hpp"
#include <vector>

namespace spark
{
	class Grid : public IContainer
	{
	public:
		Grid();

		void OnPaint(const PaintEvent& ev,const Dimension& dim);
		void OnInitialize();
		void Update(Mouse mouse, Keyboard keyboard);

		void SetVisible(const bool visible);

		void SetNumRows(int rows) { m_rows = rows; }
		void SetNumColumns(int cols) { m_columns = cols; }

	private:
		void PaintChildren(const PaintEvent& ev, const Dimension& dim);

	private:
		int m_rows;
		int m_columns;
		int m_rowHeight;
		int m_columnWidth;
	};
}