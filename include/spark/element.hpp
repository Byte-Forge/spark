#pragma once
#include <memory>
#include <set>
#include "vector.hpp"

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
        vec4<unsigned int> m_margin;
		vec4<unsigned int> m_padding;
    };
}