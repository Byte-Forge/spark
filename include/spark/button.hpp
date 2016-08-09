#pragma once
#include <string>
#include "element.hpp"
#include "image.hpp"
#include "label.hpp"


namespace spark
{	
	class Button : public IElement
	{
	public:
		Button();
	
        void OnPaint(const PaintEvent& ev,const Dimension& box);
        void OnInitialize();
		void Update(Mouse mouse);

		void SetImage(std::shared_ptr<Image> image);
		void SetHoveredImage(std::shared_ptr<Image> image);
		void SetLabel(std::shared_ptr<Label> label);
		void SetHoveredLabel(std::shared_ptr<Label> label);

		std::shared_ptr<Image>& GetHoveredImage() { return m_hovered_image; }
		std::shared_ptr<Label>& GetHoveredLabel() { return m_hovered_label; }

	private:
		std::shared_ptr<Image> m_image;
		std::shared_ptr<Image> m_hovered_image;
		std::shared_ptr<Label> m_label;
		std::shared_ptr<Label> m_hovered_label;
	};
}
