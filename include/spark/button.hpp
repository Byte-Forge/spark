#pragma once
#include <string>
#include "element.hpp"
#include "image.hpp"
#include "label.hpp"


namespace spark
{	
	class IButton : public IElement
	{
	public:
		IButton();
	
        void OnPaint(const PaintEvent& ev,const Dimension& box);
        void OnInitialize();
		void Update(Mouse mouse);

		void SetImage(const std::string& imgFile);
		void SetLabel(const std::string& text);

	private:
		std::shared_ptr<IImage> m_image;
		std::shared_ptr<ILabel> m_label;
	};
}
