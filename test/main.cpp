#include <GLFW/glfw3.h>
#include <spark/spark.hpp>
#include <iostream>

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
	if (!core.AddFont("arial-sans", "./arial.ttf"))
	{
		std::cout << "Failed to load test font arial.ttf" << std::endl;
	}
	auto view = core.CreateView(800,600);
	auto element = std::make_shared<spark::Grid>();
	
	auto label = std::make_shared<spark::ILabel>();
	label->SetText("Spark - GUI lib");
	label->SetFontSize(36.0f);
	
	auto label_margin_test = std::make_shared<spark::ILabel>();
	label_margin_test->SetText("Margin and padding test.");
	label_margin_test->SetMargin(spark::vec4<unsigned int>(50,10,100,20));
	label_margin_test->SetPadding(spark::vec4<unsigned int>(10,10,10,10));
	label_margin_test->SetBorderRadius(10);
	
	element->AddChildren(label);
	element->AddChildren(label_margin_test);
	
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
		glfwPollEvents();
    }
    return 0;
}
