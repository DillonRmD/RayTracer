#pragma once

#include "../math/Math.h"

#include <GL\glew.h>
#include <GLFW/glfw3.h>

#include <string>


namespace PLATFORM {
	class Window
	{
	public:
		Window(std::string title, MATH::Vector2D size);
		Window(std::string title, int width, int height);
		~Window();
		
		inline std::string getTitle() { return this->title; };
		inline MATH::Vector2D getSize() { return this->size; };

		void setTitle(std::string title);
		void setSize(MATH::Vector2D size);

		bool isOpen();

		void initialize();

		void update();
		void clearScreen();

	private:
		void initializeImGUI();
		void createWindow();

	private:
		GLFWwindow* glfwContext;
		std::string title;
		MATH::Vector2D size;
	};
}


