#pragma once
#include <memory>
#include <set>
#include "vector.hpp"
#include "input.hpp"

namespace spark
{
	struct PaintEvent
	{
		void* context;
		float ratio;
	};

	struct Dimension
	{
		vec4<unsigned int> box;
	};

    class IElement
    {
    public:
        IElement();
       
        virtual void OnPaint(const PaintEvent& ev,const Dimension& box) = 0;
        virtual void OnInitialize() = 0;
		virtual void Update(Mouse mouse) = 0;
        
        vec4<unsigned int> GetBackgroundColor() { return m_bg_color; }
        void SetBackgroundColor(const vec4<unsigned int> color) { m_bg_color = color; }

		vec4<unsigned int> GetMargin() { return m_margin; }
		void SetMargin(const vec4<unsigned int>& margin) { m_margin = margin; }
		
		vec4<unsigned int> GetPadding() { return m_padding; }
		void SetPadding(const vec4<unsigned int>& padding) { m_padding = padding; }
		
		float GetWidth() { return m_width; }
		void SetWidth(const float width) { m_width = width; }
		
		float GetHeight() { return m_height; }
		void SetHeight(const float height) { m_height = height; }
		
		bool IsVisible() { return m_visible; }
		void SetVisible(const bool visible) { m_visible = visible; }
		
		void Hide() { m_visible = false; }
		void Show() { m_visible = true; }
		
		int GetZIndex() { return m_index; }
		void SetZIndex(int index) { m_index = index; }
		
		float GetBorderSize() { return m_border_size; }
		void SetBorderSize(float border_size) { m_border_size = border_size; }

		vec4<unsigned int> GetBorderColor() { return m_border_color; }
		void SetBorderColor(vec4<unsigned int> border_color) { m_border_color = border_color; }
		
		float GetBorderRadius() { return m_border_radius; }
		void SetBorderRadius(float border_radius) { m_border_radius = border_radius; }

	protected:
		vec4<unsigned int> m_margin; // top, right, bottom, left
		vec4<unsigned int> m_padding; // top, right, bottom, left
		
		int m_index; // how deep is element
		
		float m_width;
		float m_height;
		
		float m_border_size;
		vec4<unsigned int> m_border_color;
		vec4<unsigned int> m_bg_color;
		float m_border_radius;
		
		bool m_visible;
    };
}
