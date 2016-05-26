#include <GLFW/glfw3.h>
#include <spark/spark.hpp>


int main(int argc,char** argv)
{
    glfwInit();

    GLFWwindow* window;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(800,600,"spark ui test",NULL,NULL);
	glfwMakeContextCurrent(window);
    glfwShowWindow(window);

	spark::Core core(true);
	auto view = core.CreateView(800,600);
	auto element = std::make_shared<spark::Grid>();
	view->SetRoot(element);
    while(!glfwWindowShouldClose(window))
    {
		int winWidth, winHeight;
		int fbWidth, fbHeight;
		float pxRatio;
		glfwGetWindowSize(window, &winWidth, &winHeight);
		glfwGetFramebufferSize(window, &fbWidth, &fbHeight);

		// Calculate pixel ration for hi-dpi devices.
		pxRatio = (float)fbWidth / (float)winWidth;

		spark::PaintEvent ev;
		ev.context = core.GetPaintContext();
		ev.ratio = pxRatio;
		view->Render(ev);

		glfwSwapBuffers(window);
    }
    return 0;
}