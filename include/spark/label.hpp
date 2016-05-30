#pragma once
#include <string>
#include "element.hpp"


namespace spark
{
	class ILabel : public IElement
	{
	public:
		ILabel();
	
        void OnPaint(const PaintEvent& ev,const Dimension& box);
        void OnInitialize();
        
		void SetText(const std::string& text) { m_text = text; }
		const std::string GetText() { return m_text; }
		
		void SetFontSize(float size) { m_size = size; }
		float GetFontSize() { return m_size; }
		
		int GetLength() { return m_text.length(); }
		
		void SetFont(const std::string& font_name) { m_font = font_name; }
		const std::string& GetFont() { return m_font;}
		
	private:
		std::string m_text;
		std::string m_font;
		
		float m_size;
	};
}
