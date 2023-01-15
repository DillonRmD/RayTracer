#pragma once

#include <string>

namespace UTIL {

	class File
	{
	public:
		File(std::string fileName);
		File();
		~File();

		inline std::string getName() { return this->name; };
		inline std::string getContents() { return this->contents; }

		void setName(std::string fileName);
		void append(std::string contents);

		void read();
		void read(std::string name);
		void write(std::string contents);

	private:
		std::string name;
		std::string contents;
	};
}

