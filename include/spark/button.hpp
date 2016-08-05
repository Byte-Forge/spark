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

		void SetImage(std::shared_ptr<IImage> image);
		void SetLabel(std::shared_ptr<ILabel> label);

	private:
		std::shared_ptr<IImage> m_image;
		std::shared_ptr<ILabel> m_label;
	};
}
