#pragma once
#include <memory>
#include <string>
#include <spark/core.hpp>
#include <spark/view.hpp>

namespace spark
{

	class XMLBuilder
	{
	public:
		XMLBuilder(std::shared_ptr<Core> &core);
		~XMLBuilder();

		std::shared_ptr<View> LoadView(const unsigned int width, const unsigned int height, const std::string &file);

	private:
		std::shared_ptr<Core> m_core;
	};
}