#include <spark/xmlbuilder.hpp>
#include <spark/button.hpp>
#include <spark/label.hpp>
#include <spark/grid.hpp>
#include <spark/stackpanel.hpp>
#include <pugixml.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include "util.hpp"

using namespace spark;

XMLBuilder::XMLBuilder(std::shared_ptr<Core> &core) : m_core(core)
{

}

XMLBuilder::~XMLBuilder()
{

}

bool ParseAttributes(std::shared_ptr<Core> core, pugi::xml_node_iterator element_node, std::shared_ptr<IElement> element)
{
	std::string type = element_node->name();
	for (pugi::xml_attribute_iterator attrib = element_node->attributes_begin(); attrib != element_node->attributes_end(); ++attrib)
	{
		std::string name = attrib->name();
		std::string value = attrib->value();

		if (name == "name")
		{
			element->SetName(value);
			core->AddNamedElement(value, element);
		}
		else if (name == "visible")
		{
			element->SetVisible(attrib->as_bool());
		}
		else if (name == "function")
		{
			element->SetFunction(core->GetFunction(value));
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

		///////////////////////////////// CONTAINER ////////////////////////////////////////
		else if (name == "image" && (type == "grid" || type == "stackpanel"))
		{
			std::dynamic_pointer_cast<IContainer> (element)->SetImage(value);
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
		else if (name == "fontSize" && type == "label")
		{
			std::dynamic_pointer_cast<ILabel> (element)->SetFontSize(std::stof(value));
		}
		else if (name == "font" && type == "label")
		{
			std::dynamic_pointer_cast<ILabel> (element)->SetFont(value);
		}
		else if (name == "fontColor" && type == "label")
		{
			std::vector<std::string> vals = split(value, ',');
			std::dynamic_pointer_cast<ILabel> (element)->SetFontColor(vec4<unsigned int>(std::stoi(vals[0]), std::stoi(vals[1]), std::stoi(vals[2]), std::stoi(vals[3])));
		}

		///////////////////////////////// BUTTON /////////////////////////////////////////////
		else if (name == "image" && type == "button")
		{
			std::dynamic_pointer_cast<IButton> (element)->SetImage(value);
		}
		else if (name == "text" && type == "button")
		{
			std::dynamic_pointer_cast<IButton> (element)->SetLabel(value);
		}

		///////////////////////////////// IMAGE /////////////////////////////////////////////
		else if (name == "image" && type == "image")
		{
			std::dynamic_pointer_cast<IImage> (element)->SetImage(value);
		}
	}
	return true;
}

std::shared_ptr<IContainer> ParseContainer(std::shared_ptr<Core> core, pugi::xml_node_iterator container_node)
{
	std::string container_type = container_node->name();
	std::shared_ptr<IContainer> container;
	if (container_type == "grid")
		container = std::make_shared<Grid>();
	else if (container_type == "stackpanel")
		container = std::make_shared<StackPanel>();

	if (!ParseAttributes(core, container_node, container))
		return nullptr;
	for (pugi::xml_node_iterator element_node = container_node->begin(); element_node != container_node->end(); ++element_node)
	{
		std::string element_type = element_node->name();
		if (element_type == "grid" || element_type == "stackpanel")
		{
			container->AddChildren(ParseContainer(core, element_node));
		}
		else if (element_type == "label")
		{
			auto element = std::make_shared<ILabel>();
			if (!ParseAttributes(core, element_node, element))
				return nullptr;
			element->SetText(element_node->child_value());
			container->AddChildren(element);
		}
		else if (element_type == "button")
		{
			auto element = std::make_shared<IButton>();
			if (!ParseAttributes(core, element_node, element))
				return nullptr;
			container->AddChildren(element);
		}
		else if (element_type == "image")
		{
			auto element = std::make_shared<IImage>();
			if (!ParseAttributes(core, element_node, element))
				return nullptr;
			container->AddChildren(element);
		}
	}
	return container;
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
	// TODO: throw error if too many root containers defined
	for (pugi::xml_node_iterator container_node = doc.begin(); container_node != doc.end(); ++container_node)
	{
		view = m_core->CreateView(width, height);
		auto container = std::make_shared<Grid>();
		for (pugi::xml_node_iterator child_container_node = container_node->begin(); child_container_node != container_node->end(); ++child_container_node)
		{
			auto child_container = ParseContainer(m_core, child_container_node);
			if (child_container == nullptr)
				return nullptr;
			container->AddChildren(child_container);
		}
		view->SetRoot(container);
	}
	return view;
}
