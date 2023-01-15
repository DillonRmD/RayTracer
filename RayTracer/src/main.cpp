
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "platform/Window.h"
#include "graphics/Shader.h"

int main(int argumentCount, char* argumentValues[])
{
	PLATFORM::Window window = PLATFORM::Window("Ray Tracer Application", 800, 600);

	window.initialize();

	GRAPHICS::Shader shader("E:\\dev\\RayTracer\\RayTracer\\src\\test.vert", "E:\\dev\\RayTracer\\RayTracer\\src\\test.frag");

	while (window.isOpen()) {

		window.clearScreen();

		shader.Activate();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();

		ImGui::NewFrame();

		ImGui::Begin("Test Window");
		ImGui::Text("Poop");
		ImGui::End();

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		window.update();
	}

	return 0;
}