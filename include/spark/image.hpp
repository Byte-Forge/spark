#pragma once
#include <string>
#include "element.hpp"


namespace spark
{	
	class Image : public IElement
	{
	public:
		Image();
		~Image();
	
        void OnPaint(const PaintEvent& ev, const Dimension& box);
        void OnInitialize();
		void Update(Mouse mouse);

		void SetImage(const std::string& imgFile);

	private:
		std::string m_file;
		int m_image = -1;
	};
}
