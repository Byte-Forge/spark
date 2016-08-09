#pragma once
#include <memory>
#include <string>
#include <spark/core.hpp>
#include <spark/view.hpp>
#include <spark/button.hpp>
#include <spark/label.hpp>
#include <spark/grid.hpp>
#include <spark/image.hpp>
#include <spark/textbox.hpp>
#include <spark/checkbox.hpp>
#include <spark/stackpanel.hpp>


#include "../deps/pugixml/src/pugixml.hpp" //stephan will love me for this^^

namespace spark
{
	class XMLBuilder
	{
	public:
		XMLBuilder(std::shared_ptr<Core> &core);
		~XMLBuilder();

		std::shared_ptr<View> LoadView(const unsigned int width, const unsigned int height, const std::string &file);

	private:
		bool ParseAttributes(pugi::xml_node_iterator element_node, std::shared_ptr<IElement> element);
		std::shared_ptr<Image> ParseImage(pugi::xml_node_iterator image_node);
		std::shared_ptr<Label> ParseLabel(pugi::xml_node_iterator label_node);
		std::shared_ptr<Checkbox> ParseCheckbox(pugi::xml_node_iterator checkbox_node);
		std::shared_ptr<Textbox> ParseTextbox(pugi::xml_node_iterator textbox_node);
		std::shared_ptr<Button> ParseButton(pugi::xml_node_iterator button_node);
		std::shared_ptr<IContainer> ParseContainer(pugi::xml_node_iterator container_node);

		void ParseStyle(pugi::xml_node_iterator container_node);

	private:
		std::shared_ptr<Core> m_core;

		std::shared_ptr<Button> m_button;
		std::shared_ptr<Label> m_button_label;
		std::shared_ptr<Label> m_label;
		std::shared_ptr<Grid> m_grid;
		std::shared_ptr<Image> m_image;
		std::shared_ptr<Textbox> m_textbox;
		std::shared_ptr<Checkbox> m_checkbox;
		std::shared_ptr<StackPanel> m_stackpanel;
	};
}