#pragma once
#include <memory>
#include <set>
#include <map>
#include <string>
#include <functional>
#include "vector.hpp"
#include "input.hpp"

namespace spark
{
	enum Orientation
	{
		VERTICAL,
		HORIZONTAL,
	};

	class View;
	
	enum Alignment
	{
		LEFT,
		RIGHT,
		TOP,
		BOTTOM,
		CENTER,
		STRETCH
	};

	struct PaintEvent
	{
		void* context;
		float ratio;
	};

	struct Dimension
	{
		//vec 4 just makes things more complicated
		int x;
		int y;
		unsigned int width;
		unsigned int height;
	};

    class IElement : public std::enable_shared_from_this<IElement>
    {
    public:
        IElement();
       
        virtual void OnPaint(const PaintEvent& ev, const Dimension& box) = 0;
		virtual void OnInitialize() = 0;
		virtual void Update(Mouse mouse, Keyboard keyboard,std::shared_ptr<View> view) = 0;

		virtual void SetVisible(const bool visible) = 0;
        
        vec4<unsigned int> GetBackgroundColor() { return m_bg_color; }
		void SetBackgroundColor(const vec4<unsigned int> color) { m_bg_color = color; m_hovered_bg_color = color; }

		vec4<unsigned int> GetMargin() { return m_margin; }
		void SetMargin(const vec4<unsigned int>& margin) { m_margin = margin; }
		
		vec4<unsigned int> GetPadding() { return m_padding; }
		void SetPadding(const vec4<unsigned int>& padding) { m_padding = padding; }
		
		float GetWidth() { return m_width; }
		void SetWidth(const float width) { m_width = width; }
		
		float GetHeight() { return m_height; }
		void SetHeight(const float height) { m_height = height; }

		void SetHorizontalAlignment(Alignment ha) { m_horizontalAlignment = ha; }
		void SetVerticalAlignment(Alignment va) { m_verticalAlignment = va; }
		
		bool IsVisible() { return m_visible; }
		
		void Hide() { SetVisible(false); }
		void Show() { SetVisible(true); }
		void Toggle() { SetVisible(!m_visible); }
		
		int GetZIndex() { return m_index; }
		void SetZIndex(int index) { m_index = index; }
		
		float GetBorderSize() { return m_border_size; }
		void SetBorderSize(float border_size) { m_border_size = border_size; }

		vec4<unsigned int> GetBorderColor() { return m_border_color; }
		void SetBorderColor(vec4<unsigned int> border_color) { m_border_color = border_color; m_hovered_border_color = border_color; }
		
		float GetBorderRadius() { return m_border_radius; }
		void SetBorderRadius(float border_radius) { m_border_radius = border_radius; }
 
		void SetName(const std::string &name) { m_name = name; }
		std::string GetName() { return m_name; }

		void SetGridRow(int row) { m_gridRow = row; }
		int GetGridRow() { return m_gridRow; }
		void SetGridColumn(int column) { m_gridColumn = column; }
		int GetGridColumn() { return m_gridColumn; }
		void SetRowSpan(int span) { m_rowSpan = span; }
		int GetRowSpan() { return m_rowSpan; }
		void SetColumnSpan(int span) { m_columnSpan = span; }
		int GetColumnSpan() { return m_columnSpan; }

		void SetHoveredBorderColor(vec4<unsigned int> border_color) { m_hovered_border_color = border_color; }
		void SetHoveredBackgroundColor(vec4<unsigned int> background_color) { m_hovered_bg_color = background_color; }

		void SetUpdateFunction(const std::string& func) { m_update = func; }
		void SetOnclickFunction(const std::string& func) { m_onclick = func; }

	protected:
		void MouseOver(Mouse mouse);
		void CalcPosition(const Dimension& box);

	protected:
		std::string m_name;

		Dimension m_box;

		std::string m_onclick;
		std::string m_update;

		vec2<int> m_position;
		vec4<unsigned int> m_margin; // top, right, bottom, left
		vec4<unsigned int> m_padding; // top, right, bottom, left
		Alignment m_horizontalAlignment;
		Alignment m_verticalAlignment;
		
		int m_index; // how deep is element
		
		unsigned int m_width;
		unsigned int m_height;
		
		float m_border_size;
		float m_border_radius;
		vec4<unsigned int> m_border_color;
		vec4<unsigned int> m_bg_color;

		vec4<unsigned int> m_hovered_border_color;
		vec4<unsigned int> m_hovered_bg_color;

		int m_gridRow;
		int m_gridColumn;
		int m_rowSpan;
		int m_columnSpan;
		
		bool m_hovered;
		bool m_visible;
    };
}
