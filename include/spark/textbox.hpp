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
		void Update(Mouse mouse);

		void SetLabel(std::shared_ptr<ILabel> label);

	private:
		std::shared_ptr<ILabel> m_label;
	};
}