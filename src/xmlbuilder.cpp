#include <spark/xmlbuilder.hpp>
#include <spark/button.hpp>
#include <spark/label.hpp>
#include <spark/grid.hpp>
#include <spark/textbox.hpp>
#include <spark/checkbox.hpp>
#include <spark/stackpanel.hpp>
#include <pugixml.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include "util.hpp"

using namespace spark;

XMLBuilder::XMLBuilder(std::shared_ptr<Core> &core) : m_core(core)
{
	m_button = std::make_shared<Button>();
	m_image = std::make_shared<Image>();
	m_label = std::make_shared<Label>();
	m_button_label = std::make_shared<Label>(*m_label);
	m_grid = std::make_shared<Grid>();
	m_textbox = std::make_shared<Textbox>();
	m_checkbox = std::make_shared<Checkbox>();
	m_stackpanel = std::make_shared<StackPanel>();
}

XMLBuilder::~XMLBuilder()
{

}

bool XMLBuilder::ParseAttributes(pugi::xml_node_iterator element_node, std::shared_ptr<IElement> element)
{
	std::string type = element_node->name();
	for (pugi::xml_attribute_iterator attrib = element_node->attributes_begin(); attrib != element_node->attributes_end(); ++attrib)
	{
		std::string name = attrib->name();
		std::string value = attrib->value();

		if (name == "name")
		{
			element->SetName(value);
			m_core->AddNamedElement(value, element);
		}
		else if (name == "visible")
		{
			element->SetVisible(attrib->as_bool());
		}
		else if (name == "update")
		{
			element->SetUpdateFunction(m_core->GetFunction(value));
		}
		else if (name == "mouseLeftDown")
		{
			element->SetMouseLeftDownFunction(m_core->GetFunction(value));
		}
		else if (name == "margin")
		{
			std::vector<std::string> vals = split(value, ',');
			element->SetMargin(vec4<unsigned int>(std::stoi(vals[0]), std::stoi(vals[1]), std::stoi(vals[2]), std::stoi(vals[3])));
		}
		else if (name == "borderSize")
		{
			element->SetBorderSize(attrib->as_float());
		}
		else if (name == "backgroundColor")
		{
			std::vector<std::string> vals = split(value, ',');
			element->SetBackgroundColor(vec4<unsigned int>(std::stoi(vals[0]), std::stoi(vals[1]), std::stoi(vals[2]), std::stoi(vals[3])));
		}
		else if (name == "width")
		{
			element->SetWidth(attrib->as_int());
		}
		else if (name == "height")
		{
			element->SetHeight(attrib->as_int());
		}
		else if (name == "borderRadius")
		{
			element->SetBorderRadius(std::stoi(value));
		}
		else if (name == "borderSize")
		{
			element->SetBorderSize(std::stoi(value));
		}
		else if (name == "borderColor")
		{
			std::vector<std::string> vals = split(value, ',');
			element->SetBorderColor(vec4<unsigned int>(std::stoi(vals[0]), std::stoi(vals[1]), std::stoi(vals[2]), std::stoi(vals[3])));
		}
		else if (name == "grid.row")
		{
			element->SetGridRow(std::stoi(value));
		}
		else if (name == "grid.column")
		{
			element->SetGridColumn(std::stoi(value));
		}
		else if (name == "grid.rowSpan")
		{
			element->SetRowSpan(std::stoi(value));
		}
		else if (name == "grid.columnSpan")
		{
			element->SetColumnSpan(std::stoi(value));
		}
		else if (name == "verticalAlignment")
		{
			if (value == "top")
				element->SetVerticalAlignment(TOP);
			else if (value == "bottom")
				element->SetVerticalAlignment(BOTTOM);
			else if (value == "center")
				element->SetVerticalAlignment(CENTER);
			else if (value == "stretch")
				element->SetVerticalAlignment(STRETCH);
			else
			{
				std::cout << "WARNING! " << value << " is not valid for horizontal alignment: (top, bottom, center, stretch)" << std::endl;
				return false;
			}
		}
		else if (name == "horizontalAlignment")
		{
			if (value == "left")
				element->SetHorizontalAlignment(LEFT);
			else if (value == "right")
				element->SetHorizontalAlignment(RIGHT);
			else if (value == "center")
				element->SetHorizontalAlignment(CENTER);
			else if (value == "stretch")
				element->SetHorizontalAlignment(STRETCH);
			else
			{
				std::cout << "WARNING! " << value << " is not valid for horizontal alignment: (left, right, center, stretch)" << std::endl;
				return false;
			}
		}

		///////////////////////////////// GRID ////////////////////////////////////////
		else if (name == "rows" && type == "grid")
		{
			std::dynamic_pointer_cast<Grid> (element)->SetNumRows(std::stoi(value));
		}
		else if (name == "columns" && type == "grid")
		{
			std::dynamic_pointer_cast<Grid> (element)->SetNumColumns(std::stoi(value));
		}

		///////////////////////////////// STACKPANEL ////////////////////////////////////////
		else if (name == "orientation" && type == "stackpanel")
		{
			if (value == "vertical")
				std::dynamic_pointer_cast<StackPanel> (element)->SetOrientation(VERTICAL);
			else if (value == "horizontal")
				std::dynamic_pointer_cast<StackPanel> (element)->SetOrientation(HORIZONTAL);
			else
			{
				std::cout << "WARNING! " << value << " is not valid for stackpanel orientation: (vertical, horizontal)" << std::endl;
				return false;
			}
		}

		///////////////////////////////// LABEL /////////////////////////////////////////////
		else if (name == "text" && ends_with(type, "label"))
		{
			std::dynamic_pointer_cast<Label> (element)->SetText(value);
		}
		else if (name == "fontSize" && ends_with(type, "label"))
		{
			std::dynamic_pointer_cast<Label> (element)->SetFontSize(std::stof(value));
		}
		else if (name == "font" && ends_with(type, "label"))
		{
			std::dynamic_pointer_cast<Label> (element)->SetFont(value);
		}
		else if (name == "fontColor" && ends_with(type, "label"))
		{
			std::vector<std::string> vals = split(value, ',');
			std::dynamic_pointer_cast<Label> (element)->SetFontColor(vec4<unsigned int>(std::stoi(vals[0]), std::stoi(vals[1]), std::stoi(vals[2]), std::stoi(vals[3])));
		}

		///////////////////////////////// IMAGE /////////////////////////////////////////////
		else if (name == "file" && ends_with(type, "image"))
		{
			std::dynamic_pointer_cast<Image> (element)->SetImage(value);
		}
	}
	return true;
}

bool ParseHoverAttributes(std::shared_ptr<Core> core, pugi::xml_node_iterator element_node, std::shared_ptr<IElement> element)
{
	std::string type = element_node->name();
	for (pugi::xml_attribute_iterator attrib = element_node->attributes_begin(); attrib != element_node->attributes_end(); ++attrib)
	{
		std::string name = attrib->name();
		std::string value = attrib->value();

		if (name == "borderColor")
		{
			std::vector<std::string> vals = split(value, ',');
			element->SetHoveredBorderColor(vec4<unsigned int>(std::stoi(vals[0]), std::stoi(vals[1]), std::stoi(vals[2]), std::stoi(vals[3])));
		}
		else if (name == "backgroundColor")
		{
			std::vector<std::string> vals = split(value, ',');
			element->SetHoveredBackgroundColor(vec4<unsigned int>(std::stoi(vals[0]), std::stoi(vals[1]), std::stoi(vals[2]), std::stoi(vals[3])));
		}
		else
		{
			std::cout << "Waring!: " << name << " is not a valid argument for .hover properties!" << std::endl;
			return false;
		}
	}
	return true;
}

std::shared_ptr<Image> XMLBuilder::ParseImage(pugi::xml_node_iterator image_node)
{
	std::shared_ptr<Image> image = std::make_shared<Image>(*m_image);

	if (!ParseAttributes(image_node, image))
		std::cout << "Warning! : problems parsing the image attributes." << std::endl;
	return image;
}

std::shared_ptr<Label> XMLBuilder::ParseLabel(pugi::xml_node_iterator label_node)
{
	std::shared_ptr<Label> label = std::make_shared<Label>(*m_label);

	if (!ParseAttributes(label_node, label))
		std::cout << "Warning! : problems parsing the label attributes." << std::endl;
	return label;
}

std::shared_ptr<Checkbox> XMLBuilder::ParseCheckbox(pugi::xml_node_iterator checkbox_node)
{
	std::shared_ptr<Checkbox> checkbox = std::make_shared<Checkbox>(*m_checkbox);

	if (!ParseAttributes(checkbox_node, checkbox))
		std::cout << "Warning! : problems parsing the checkbox attributes." << std::endl;
	return checkbox;
}

std::shared_ptr<Textbox> XMLBuilder::ParseTextbox(pugi::xml_node_iterator textbox_node)
{
	std::shared_ptr<Textbox> textbox = std::make_shared<Textbox>(*m_textbox);

	if (!ParseAttributes(textbox_node, textbox))
		std::cout << "Warning! : problems parsing the textbox attributes." << std::endl;
	for (pugi::xml_node_iterator element_node = textbox_node->begin(); element_node != textbox_node->end(); ++element_node)
	{
		std::string element_type = element_node->name();
		if (element_type == "textbox.label")
		{
			std::cout << "test" << std::endl;
			textbox->SetLabel(ParseLabel(element_node));
		}
	}
	return textbox;
}

std::shared_ptr<Button> XMLBuilder::ParseButton(pugi::xml_node_iterator button_node)
{
	std::shared_ptr<Button> button = std::make_shared<Button>(*m_button);
	if (!ParseAttributes(button_node, button))
		std::cout << "Warning! : problems parsing the button attributes." << std::endl;
	for (pugi::xml_node_iterator element_node = button_node->begin(); element_node != button_node->end(); ++element_node)
	{
		std::string element_type = element_node->name();
		if (element_type == "button.label")
		{
			button->SetLabel(ParseLabel(element_node));
			button->SetHoveredLabel(ParseLabel(element_node));
		}
		else if (element_type == "button.image")
		{
			button->SetImage(ParseImage(element_node));
			button->SetHoveredImage(ParseImage(element_node));
		}
		else if (element_type == "button.hover")
		{
			if (!ParseHoverAttributes(m_core, element_node, button))
				std::cout << "Warning! : problems parsing the button hover attributes." << std::endl;
			for (pugi::xml_node_iterator child_node = element_node->begin(); child_node != element_node->end(); ++child_node)
			{
				std::string element_type = child_node->name();
				if (element_type == "button.hover.label")
				{
					if (!ParseAttributes(child_node, button->GetHoveredLabel()))
						std::cout << "Warning! : problems parsing the button hover label attributes." << std::endl;
				}
				else if (element_type == "button.hover.image")
				{
					if (!ParseAttributes(child_node, button->GetHoveredImage()))
						std::cout << "Warning! : problems parsing the button hover image attributes." << std::endl;
				}
			}
		}
	}
	return button;
}


std::shared_ptr<IContainer> XMLBuilder::ParseContainer(pugi::xml_node_iterator container_node)
{
	std::string container_type = container_node->name();
	std::shared_ptr<IContainer> container;
	if (container_type == "grid")
	{
		container = std::make_shared<Grid>();
	}
	else if (container_type == "stackpanel")
	{
		container = std::make_shared<StackPanel>();
	}
	else
	{
		container = std::make_shared<Grid>();
	}

	if (!ParseAttributes(container_node, container))
		return nullptr;
	for (pugi::xml_node_iterator element_node = container_node->begin(); element_node != container_node->end(); ++element_node)
	{
		std::string element_type = element_node->name();
		if (element_type == "grid.image")
		{
			container->SetImage(ParseImage(element_node));
		}
		else if (element_type == "grid" || element_type == "stackpanel")
		{
			container->AddChild(ParseContainer(element_node));
		}
		else if (element_type == "button")
		{
			container->AddChild(ParseButton(element_node));
		}
		else if (element_type == "label")
		{
			container->AddChild(ParseLabel(element_node));
		}
		else if (element_type == "image")
		{
			container->AddChild(ParseImage(element_node));
		}
		else if (element_type == "textbox")
		{
			container->AddChild(ParseTextbox(element_node));
		}
		else if (element_type == "checkbox")
		{
			container->AddChild(ParseCheckbox(element_node));
		}
	}
	return container;
}

void XMLBuilder::ParseStyle(pugi::xml_node_iterator style_node)
{
	for (pugi::xml_node_iterator element_node = style_node->begin(); element_node != style_node->end(); ++element_node)
	{
		std::string element_type = element_node->name();
		if (element_type == "grid")
		{
			m_grid = std::dynamic_pointer_cast<Grid>(ParseContainer(element_node));
		}
		else if (element_type == "stackpanel")
		{
			m_stackpanel = std::dynamic_pointer_cast<StackPanel>(ParseContainer(element_node));
		}
		else if (element_type == "button")
		{
			m_button = ParseButton(element_node);
		}
		else if (element_type == "label")
		{
			m_label = ParseLabel(element_node);
		}
		else if (element_type == "image")
		{
			m_image = ParseImage(element_node);
		}
		else if (element_type == "textbox")
		{
			m_textbox = ParseTextbox(element_node);
		}
		else if (element_type == "checkbox")
		{
			m_checkbox = ParseCheckbox(element_node);
		}
	}
}

std::shared_ptr<View> XMLBuilder::LoadView(const unsigned int width, const unsigned int height, const std::string &file)
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(file.c_str());
	pugi::xml_node root = doc.document_element();

	if (!result)
	{
		std::cout << "XML [" << file << "] parsed with errors, attr value: [" << doc.child("node").attribute("attr").value() << "]\n";
		std::cout << "Error description: " << result.description() << "\n";
		std::cout << "Error offset: " << result.offset << " (error at [..." << (file.front() + result.offset) << "]\n\n";
		return nullptr;
	}

	std::shared_ptr<View> view;

	pugi::xml_node style_node = doc.child("style");
	ParseStyle(style_node);

	pugi::xml_node container_node = doc.child("grid");
	view = m_core->CreateView(width, height);
	view->SetRoot(ParseContainer(container_node));

	return view;
}
