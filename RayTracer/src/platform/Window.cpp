#include "Window.h"

#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"

namespace PLATFORM {

	Window::Window(std::string title, MATH::Vector2D size)
	{
		setTitle(title);
		setSize(size);
	}

	Window::Window(std::string title, int width, int height)
	{
		setTitle(title);
		setSize(MATH::Vector2D(width, height));
		
	}

	Window::~Window()
	{
		ImGui_ImplGlfw_Shutdown();
		ImGui_ImplOpenGL3_Shutdown();
		glfwDestroyWindow(this->glfwContext);
		glfwTerminate();
	}

	void Window::setTitle(std::string title)
	{
		this->title = title;
	}

	void Window::setSize(MATH::Vector2D size)
	{
		this->size = size;
	}

	bool Window::isOpen()
	{
		return !glfwWindowShouldClose(this->glfwContext);
	}

	void Window::clearScreen()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update()
	{
		glfwSwapBuffers(this->glfwContext);
		glfwPollEvents();
	}

	void Window::initialize()
	{
		glfwInit();

		createWindow();

		glfwMakeContextCurrent(this->glfwContext);

		glewInit();

		initializeImGUI();
	}

	void Window::initializeImGUI()
	{
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(this->glfwContext, true);
		ImGui_ImplOpenGL3_Init("#version 330");
	}

	void Window::createWindow()
	{
		this->glfwContext = glfwCreateWindow(this->size.getX(), this->size.getY(), this->title.c_str(), NULL, NULL);
		if (!this->glfwContext) {
			glfwTerminate();
		}
	}

}
