#include <spark/xmlbuilder.hpp>
#include <spark/button.hpp>
#include <spark/label.hpp>
#include <spark/grid.hpp>
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

void ParseAttributes(std::shared_ptr<Core> core, pugi::xml_node_iterator element_node, std::shared_ptr<IElement> element)
{
	std::string type = element_node->name();
	for (pugi::xml_attribute_iterator attrib = element_node->attributes_begin(); attrib != element_node->attributes_end(); ++attrib)
	{
		std::string name = attrib->name();
		std::string value = attrib->value();
		if (name == "function")
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
			element->SetBorderSize(std::stof(value));
		}
		else if (name == "backgroundColor")
		{
			std::vector<std::string> vals = split(value, ',');
			element->SetBackgroundColor(vec4<unsigned int>(std::stoi(vals[0]), std::stoi(vals[1]), std::stoi(vals[2]), std::stoi(vals[3])));
		}
		else if (name == "width")
		{
			element->SetWidth(std::stoi(value));
		}
		else if (name == "height")
		{
			element->SetHeight(std::stoi(value));
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

		///////////////////////////////// BUTTON /////////////////////////////////////////////
		else if (name == "image" && type == "button")
		{
			std::dynamic_pointer_cast<IButton> (element)->SetImage(value);
		}

		///////////////////////////////// IMAGE /////////////////////////////////////////////
		else if (name == "image" && type == "image")
		{
			std::dynamic_pointer_cast<IImage> (element)->SetImage(value);
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
	for (pugi::xml_node_iterator view_node = doc.begin(); view_node != doc.end(); ++view_node)
	{
		view = m_core->CreateView(width, height);
		for (pugi::xml_node_iterator container_node = view_node->begin(); container_node != view_node->end(); ++container_node)
		{
			auto container = std::make_shared<Grid>();
			for (pugi::xml_node_iterator element_node = container_node->begin(); element_node != container_node->end(); ++element_node)
			{
				std::string element_type = element_node->name();
				if (element_type == "label")
				{
					auto element = std::make_shared<ILabel>();
					ParseAttributes(m_core, element_node, element);
					element->SetText(element_node->child_value());
					container->AddChildren(element);
				}
				else if (element_type == "button")
				{
					auto element = std::make_shared<IButton>();
					ParseAttributes(m_core, element_node, element);
					container->AddChildren(element);
				}
				else if (element_type == "image")
				{
					auto element = std::make_shared<IImage>();
					ParseAttributes(m_core, element_node, element);
					container->AddChildren(element);
				}
			}
			view->SetRoot(container);
		}
	}
	return view;
}
