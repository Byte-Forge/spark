#pragma once
#include <memory>
#include <vector>
#include <string>
#include <functional>
#include "element.hpp"
#include "label.hpp"
#include "button.hpp"
#include "view.hpp"

namespace spark
{
    class Core
    {
	private:
		struct priv;

    public:
        Core(const bool initGL);
        ~Core();

        std::shared_ptr<View> CreateView(const unsigned int width, const unsigned int height);
	
		void* GetPaintContext();
		//Add a font from file. Name is the name that will be used later to use that font
		bool AddFont(const std::string& name, const std::string& path);
		//Add a font from memory. Name is the name that will be used later to use that font
		bool AddFont(const std::string& name, const uint8_t* memory, const int size);

		void AddFunction(std::string name, std::function<void(std::shared_ptr<spark::IElement>)> func) { m_functions[name] = func; }
		std::function<void(std::shared_ptr<spark::IElement>)> GetFunction(std::string &name);

		void AddNamedElement(std::string &name, std::shared_ptr<IElement> e) { m_namedElements[name] = e; }
		std::shared_ptr<IElement>& GetNamedElement(std::string name);

		void CreateButton(std::string &name);

    private:
		std::map<std::string, std::function<void(std::shared_ptr<spark::IElement>)>> m_functions;
		std::map<std::string, std::shared_ptr<IElement>> m_namedElements;
        std::vector<std::shared_ptr<View>> m_views;
		std::unique_ptr<priv> m_private;
    };
};