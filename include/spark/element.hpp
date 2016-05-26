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

	struct Dimension
	{
		vec4<unsigned int> box;
	};

    class IElement
    {
    public:
        IElement();
       
        virtual void OnPaint(const PaintEvent& ev,const Dimension& box) = 0;
        virtual void OnInitialize() = 0;
	protected:
        vec4<unsigned int> m_margin;
		vec4<unsigned int> m_padding;
    };
}