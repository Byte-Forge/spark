#include <spark/grid.hpp>
#include <nanovg.h>
using namespace spark;

void Grid::OnInitialize()
{

}

void Grid::OnPaint(const PaintEvent& ev)
{
	auto* vg = (NVGcontext*)ev.context;
	nvgCircle(vg, 50.0, 50.0, 20.0);
	nvgFill(vg);
}