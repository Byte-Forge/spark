#pragma once
#include "element.hpp"
#include "label.hpp"
#include <string>
#include <memory>

namespace spark
{
	class Textbox : public IElement
	{
	public:
		Textbox();
		~Textbox();

		void OnPaint(const PaintEvent& ev, const Dimension& box);
		void OnInitialize();
		void Update(Mouse mouse, Keyboard keyboard,std::shared_ptr<View> view);

		void SetVisible(const bool visible);

		void SetLabel(std::shared_ptr<Label> label);

	private:
		std::shared_ptr<Label> m_label;
	};
}