#include "File.h"

#include <fstream>
#include <iostream>
#include <cassert>

namespace UTIL {
	File::File()
	{
	}

	File::File(std::string fileName)
	{
		this->name = fileName;
	}

	File::~File()
	{
	}

	void File::setName(std::string fileName)
	{
		this->name = fileName;
		write(this->contents);
	}

	void File::append(std::string contents)
	{
		std::ofstream fileContext(this->name, std::ios::app);
		fileContext << contents;
		fileContext.close();
	}

	void File::read()
	{
		std::ifstream fileContext(this->name);
		if (!fileContext.is_open()) {
			//ERROR
			assert(!"%s file not found!", this->name);
		}

		std::string currentLine;
		while (!fileContext.eof()){
			std::getline(fileContext, currentLine);
			this->contents += currentLine + "\n";
		}

		fileContext >> this->contents;
		fileContext.close();
	}

	void File::read(std::string name)
	{
		this->name = name;
		read();
	}

	void File::write(std::string contents)
	{
		std::ofstream fileContext(this->name);
		fileContext << contents;
		this->contents = contents;
		fileContext.close();
	}
}