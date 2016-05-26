#pragma once
#include <memory>
#include <vector>
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
    private:
        std::vector<std::shared_ptr<View>> m_views;
		std::unique_ptr<priv> m_private;
    };
};