#pragma once
#include <memory>
#include <set>

namespace spark
{
	struct PaintEvent
	{
		void* context;
		float ratio;
	};

    class IElement
    {
    public:
        IElement();
       
        virtual void OnPaint(const PaintEvent& ev) = 0;
        virtual void OnInitialize() = 0;
	protected:
        unsigned int m_margin;
        unsigned int m_padding;
    };
}