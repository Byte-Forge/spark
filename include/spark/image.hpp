#pragma once
#include <string>
#include "element.hpp"


namespace spark
{	
	class IImage : public IElement
	{
	public:
		IImage(const std::string& file);
		~IImage();
	
        void OnPaint(const PaintEvent& ev, const Dimension& box);
        void OnInitialize();
		void Update(Mouse mouse);

	private:
		const std::string m_file;
		int m_image = -1;
	};
}
