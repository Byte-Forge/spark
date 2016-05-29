#pragma once
#include <memory>
#include <set>
#include "vector.hpp"

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
        
		vec4<unsigned int> GetMargin() { return m_margin; }
		void SetMargin(vec4<unsigned int> margin) { m_margin = margin; }
		
		vec4<unsigned int> GetPadding() { return m_padding; }
		void SetPadding(vec4<unsigned int> padding) { m_padding = padding; }
		
		float GetWidth() { return m_width; }
		void SetWidth(float width) { m_width = width; }
		
		float GetHeight() { return m_height; }
		void SetHeight(float height) { m_height = height; }
		
		bool IsVisible() { return m_visible; }
		void SetVisible(bool visible) { m_visible = visible; }
		
		void Hide() { m_visible = false; }
		void Show() { m_visible = true; }
		
		int GetZIndex() { return m_index; }
		void SetZIndex(int index) { m_index = index; }
		
	protected:
		vec4<unsigned int> m_margin; // top, right, bottom, left
		vec4<unsigned int> m_padding; // top, right, bottom, left
		
		int m_index; // how deep is element
		
		float m_width;
		float m_height;
		
		bool m_visible;
    };
}
