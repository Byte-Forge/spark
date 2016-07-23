#pragma once
#include <memory>
#include <vector>
#include <string>
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
		bool AddFont(const std::string& name,const std::string& path);
		//Add a font from memory. Name is the name that will be used later to use that font
		bool AddFont(const std::string& name,const uint8_t* memory,const int size);

    private:
        std::vector<std::shared_ptr<View>> m_views;
		std::unique_ptr<priv> m_private;
    };
};