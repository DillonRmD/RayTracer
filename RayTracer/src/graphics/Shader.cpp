#include "Shader.h"

#include <string>
#include <cassert>

namespace GRAPHICS {

	Shader::Shader(std::string vertexShaderFileName, std::string fragmentShaderFileName)
	{
		this->vertexShaderFileContext.read(vertexShaderFileName);
		this->fragmentShaderFileContext.read(fragmentShaderFileName);

		compile();
		createProgram();
	}

	Shader::Shader(UTIL::File vertexShaderFileContext, UTIL::File fragmentShaderFileContext)
	{
		this->vertexShaderFileContext = vertexShaderFileContext;
		this->vertexShaderFileContext.read();

		this->fragmentShaderFileContext = fragmentShaderFileContext;
		this->fragmentShaderFileContext.read();

		compile();
		createProgram();
	}

	Shader::~Shader()
	{
		glDeleteProgram(this->programID); this->programID = 0;
		glDeleteShader(this->vertexShaderID); this->vertexShaderID = 0;
		glDeleteShader(this->fragmentShaderID); this->fragmentShaderID = 0;
	}

	void Shader::setVersion(std::string version)
	{
		this->version = version + "\n";
	}

	void Shader::Activate()
	{
		glUseProgram(this->programID);
	}

	void Shader::Deactivate()
	{
		glUseProgram(0);
	}

	void Shader::compile()
	{
		this->vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		char* vertexSource = retrieveGLCompatibleShaderSource(this->vertexShaderFileContext);
		glShaderSource(this->vertexShaderID, 1, &vertexSource, NULL);
		glCompileShader(this->vertexShaderID);
		validateCompilation(this->vertexShaderID);
		delete vertexSource;

		this->fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		char* fragmentSource = retrieveGLCompatibleShaderSource(this->fragmentShaderFileContext);
		glShaderSource(this->fragmentShaderID, 1, &fragmentSource, NULL);
		glCompileShader(this->fragmentShaderID);
		validateCompilation(this->fragmentShaderID);
		delete fragmentSource;
	}

	void Shader::createProgram()
	{
		this->programID = glCreateProgram();
		glAttachShader(this->programID, this->vertexShaderID);
		glAttachShader(this->programID, this->fragmentShaderID);
		glLinkProgram(this->programID);
		validateLinkage();
	}

	void Shader::validateLinkage()
	{
		int successfullyLinked = GL_FALSE;
		glGetProgramiv(this->programID, GL_LINK_STATUS, &successfullyLinked);
		if (successfullyLinked != GL_TRUE) {
			int linkageInformationLength = 0;
			glGetProgramiv(this->programID, GL_INFO_LOG_LENGTH, &linkageInformationLength);

			char* linkageInformation = (char*)malloc(linkageInformationLength);
			glGetProgramInfoLog(this->programID, linkageInformationLength, NULL, linkageInformation);
			assert(!"SHADER LINKAGE ERROR: %s", linkageInformation);
			free(linkageInformation);
		}
	}

	void Shader::validateCompilation(unsigned int shaderID)
	{
		int successfullyCompiled = GL_FALSE;
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &successfullyCompiled);
		if (successfullyCompiled != GL_TRUE) {
			int compilationInformationLength = 0;
			glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &compilationInformationLength);

			char* compilationInformation = (char*)malloc(compilationInformationLength);
			glGetShaderInfoLog(shaderID, compilationInformationLength, NULL, compilationInformation);
			assert(!"SHADER COMPILATION ERROR: %s", compilationInformation);
			free(compilationInformation);
		}
	}

	char* Shader::retrieveGLCompatibleShaderSource(UTIL::File shaderFile)
	{
		unsigned int size = (this->version.length() + shaderFile.getContents().length()) + 1;
		char* source = new char[size];
		strcpy_s(source, size, (this->version + shaderFile.getContents()).c_str());
		return source;
	}
}
