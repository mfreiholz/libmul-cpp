#include "BufferedLineReader.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	mul::BufferedLineReader lineReader;
	lineReader.append("LINE1\n", 6);
	lineReader.append("LINE2\n", 6);
	lineReader.append("LINE3\n", 6);
	lineReader.append("LINE4\n", 6);

	std::string line;
	while (!(line = lineReader.get()).empty())
	{
		std::cout << line << std::endl;
	}
}