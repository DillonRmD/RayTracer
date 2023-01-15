#pragma once

#include "../util/File.h"

#include <GL\glew.h>

namespace GRAPHICS {
	class Shader
	{
	public:
		Shader(std::string vertexShaderFileName, std::string fragmentShaderFileName);
		Shader(UTIL::File vertexShaderFileContext, UTIL::File fragmentShaderFileContext);
		~Shader();

		void setVersion(std::string version);
		std::string getVersion() { return this->version; }

		void Activate();
		void Deactivate();

	private:
		std::string version = "#version 330 core\n";
		char* retrieveGLCompatibleShaderSource(UTIL::File shaderFile);
		void createProgram();
		void compile();
		void validateCompilation(unsigned int shaderID);
		void validateLinkage();

	private:
		UTIL::File vertexShaderFileContext;
		UTIL::File fragmentShaderFileContext;

		unsigned int programID;

		unsigned int vertexShaderID;
		unsigned int fragmentShaderID;
	};
}


