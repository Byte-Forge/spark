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

std::shared_ptr<Grid> ParseGrid(std::shared_ptr<Core> core, pugi::xml_node_iterator grid_node);
std::shared_ptr<StackPanel> ParseStackPanel(std::shared_ptr<Core> core, pugi::xml_node_iterator stackpanel_node);

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
		else if (name == "update")
		{
			element->SetUpdateFunction(core->GetFunction(value));
		}
		else if (name == "mouseLeftDown")
		{
			element->SetMouseLeftDownFunction(core->GetFunction(value));
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
		else if (name == "text" && (type == "label" || type == "button.label" || type == "textbox.label" || type == "button.hover.label"))
		{
			std::dynamic_pointer_cast<ILabel> (element)->SetText(value);
		}
		else if (name == "fontSize" && (type == "label" || type == "button.label" || type == "textbox.label" || type == "button.hover.label"))
		{
			std::dynamic_pointer_cast<ILabel> (element)->SetFontSize(std::stof(value));
		}
		else if (name == "font" && (type == "label" || type == "button.label" || type == "textbox.label" || type == "button.hover.label"))
		{
			std::dynamic_pointer_cast<ILabel> (element)->SetFont(value);
		}
		else if (name == "fontColor" && (type == "label" || type == "button.label" || type == "textbox.label" || type == "button.hover.label"))
		{
			std::vector<std::string> vals = split(value, ',');
			std::dynamic_pointer_cast<ILabel> (element)->SetFontColor(vec4<unsigned int>(std::stoi(vals[0]), std::stoi(vals[1]), std::stoi(vals[2]), std::stoi(vals[3])));
		}

		///////////////////////////////// IMAGE /////////////////////////////////////////////
		else if (name == "file" && (type == "image" || type == "grid.image" || type == "stackpanel.image" || type == "button.image" || type == "button.hover.image"))
		{
			std::dynamic_pointer_cast<IImage> (element)->SetImage(value);
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

		std::cout << value << std::endl;

		if (name == "borderColor")
		{
			std::cout << value << std::endl;
			std::vector<std::string> vals = split(value, ',');
			element->SetHoveredBorderColor(vec4<unsigned int>(std::stoi(vals[0]), std::stoi(vals[1]), std::stoi(vals[2]), std::stoi(vals[3])));
		}
		else if (name == "backgroundColor")
		{
			std::vector<std::string> vals = split(value, ',');
			std::cout << value << std::endl;
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

std::shared_ptr<IImage> ParseImage(std::shared_ptr<Core> core, pugi::xml_node_iterator image_node)
{
	std::shared_ptr<IImage> image = std::make_shared<IImage>();

	if (!ParseAttributes(core, image_node, image))
		return nullptr;
	return image;
}

std::shared_ptr<ILabel> ParseLabel(std::shared_ptr<Core> core, pugi::xml_node_iterator label_node)
{
	std::shared_ptr<ILabel> label = std::make_shared<ILabel>();

	if (!ParseAttributes(core, label_node, label))
		return nullptr;
	return label;
}

std::shared_ptr<Checkbox> ParseCheckbox(std::shared_ptr<Core> core, pugi::xml_node_iterator checkbox_node)
{
	std::shared_ptr<Checkbox> checkbox = std::make_shared<Checkbox>();

	if (!ParseAttributes(core, checkbox_node, checkbox))
		return nullptr;
	return checkbox;
}

std::shared_ptr<Textbox> ParseTextbox(std::shared_ptr<Core> core, pugi::xml_node_iterator textbox_node)
{
	std::shared_ptr<Textbox> textbox = std::make_shared<Textbox>();

	if (!ParseAttributes(core, textbox_node, textbox))
		return nullptr;
	for (pugi::xml_node_iterator element_node = textbox_node->begin(); element_node != textbox_node->end(); ++element_node)
	{
		std::string element_type = element_node->name();
		if (element_type == "textbox.label")
		{
			textbox->SetLabel(ParseLabel(core, element_node));
		}
	}
	return textbox;
}

std::shared_ptr<IButton> ParseButton(std::shared_ptr<Core> core, pugi::xml_node_iterator button_node)
{
	std::shared_ptr<IButton> button = std::make_shared<IButton>();

	if (!ParseAttributes(core, button_node, button))
		return nullptr;
	for (pugi::xml_node_iterator element_node = button_node->begin(); element_node != button_node->end(); ++element_node)
	{
		std::string element_type = element_node->name();
		if (element_type == "button.label")
		{
			button->SetLabel(ParseLabel(core, element_node));
			button->SetHoveredLabel(ParseLabel(core, element_node));
		}
		else if (element_type == "button.image")
		{
			button->SetImage(ParseImage(core, element_node));
			button->SetHoveredImage(ParseImage(core, element_node));
		}
		else if (element_type == "button.hover")
		{
			if (!ParseHoverAttributes(core, element_node, button))
				return nullptr;
			for (pugi::xml_node_iterator child_node = element_node->begin(); child_node != element_node->end(); ++child_node)
			{
				std::string element_type = child_node->name();
				if (element_type == "button.hover.label")
				{
					if (!ParseAttributes(core, child_node, button->GetHoveredLabel()))
						return nullptr;
				}
				else if (element_type == "button.hover.image")
				{
					if (!ParseAttributes(core, child_node, button->GetHoveredImage()))
						return nullptr;
				}
			}
		}
	}
	return button;
}

std::shared_ptr<StackPanel> ParseStackPanel(std::shared_ptr<Core> core, pugi::xml_node_iterator stackpanel_node)
{
	std::shared_ptr<StackPanel> stackpanel = std::make_shared<StackPanel>();

	if (!ParseAttributes(core, stackpanel_node, stackpanel))
		return nullptr;
	for (pugi::xml_node_iterator element_node = stackpanel_node->begin(); element_node != stackpanel_node->end(); ++element_node)
	{
		std::string element_type = element_node->name();
		if (element_type == "stackpanel.image")
		{
			stackpanel->SetImage(ParseImage(core, element_node));
		}
		else if (element_type == "grid")
		{
			stackpanel->AddChildren(ParseGrid(core, element_node));
		}
		else if (element_type == "stackpanel")
		{
			stackpanel->AddChildren(ParseStackPanel(core, element_node));
		}
		else if (element_type == "button")
		{
			stackpanel->AddChildren(ParseButton(core, element_node));
		}
		else if (element_type == "label")
		{
			stackpanel->AddChildren(ParseLabel(core, element_node));
		}
		else if (element_type == "image")
		{
			stackpanel->AddChildren(ParseImage(core, element_node));
		}
		else if (element_type == "textbox")
		{
			stackpanel->AddChildren(ParseTextbox(core, element_node));
		}
		else if (element_type == "checkbox")
		{
			stackpanel->AddChildren(ParseCheckbox(core, element_node));
		}
	}
	return stackpanel;
}


std::shared_ptr<Grid> ParseGrid(std::shared_ptr<Core> core, pugi::xml_node_iterator grid_node)
{
	std::shared_ptr<Grid> grid = std::make_shared<Grid>();

	if (!ParseAttributes(core, grid_node, grid))
		return nullptr;
	for (pugi::xml_node_iterator element_node = grid_node->begin(); element_node != grid_node->end(); ++element_node)
	{
		std::string element_type = element_node->name();
		if (element_type == "grid.image")
		{
			grid->SetImage(ParseImage(core, element_node));
		}
		else if (element_type == "grid")
		{
			grid->AddChildren(ParseGrid(core, element_node));
		}
		else if (element_type == "stackpanel")
		{
			grid->AddChildren(ParseStackPanel(core, element_node));
		}
		else if (element_type == "button")
		{
			grid->AddChildren(ParseButton(core, element_node));
		}
		else if (element_type == "label")
		{
			grid->AddChildren(ParseLabel(core, element_node));
		}
		else if (element_type == "image")
		{
			grid->AddChildren(ParseImage(core, element_node));
		}
		else if (element_type == "textbox")
		{
			grid->AddChildren(ParseTextbox(core, element_node));
		}
		else if (element_type == "checkbox")
		{
			grid->AddChildren(ParseCheckbox(core, element_node));
		}
	}
	return grid;
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
	int root_count = 0;
	for (pugi::xml_node_iterator container_node = doc.begin(); container_node != doc.end(); ++container_node)
	{
		if (root_count == 1)
		{
			std::cout << "!Error: too many root elements in file: " << file << std::endl;
			return nullptr;
		}
		view = m_core->CreateView(width, height);
		auto container = std::make_shared<Grid>();
		std::string container_type = container_node->name();
		if (container_type == "grid")
		{
			view->SetRoot(ParseGrid(m_core, container_node));
		}
		else if (container_type == "stackpanel")
		{
			view->SetRoot(ParseStackPanel(m_core, container_node));
		}
		else
		{
			std::cout << "!Error: invalid root element " << container_type << " in file: " << file << std::endl;
			return nullptr;
		}
		root_count++;
	}
	return view;
}
