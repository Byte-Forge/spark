#pragma once
#include <string>
#include "element.hpp"
#include "image.hpp"


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

	private:
		vec4<unsigned int> m_border_box;
		std::shared_ptr<IImage> m_image;
	};
}
