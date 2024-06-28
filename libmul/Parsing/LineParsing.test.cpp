#include "LineParsing.hpp"
#include <cassert>

int main(int argc, char** argv)
{
	const int expected_line_count = 4;
	std::string str("Line1\nLine2\n\rLine3\n\rLine4\n\r");
	for (int i = 0; i < expected_line_count; i++)
	{
		str += "LINE_" + std::to_string(i) + "\n\r";
	}

	int line_counter = 0;
	std::string line;
	size_t bytes_read = 0;

	char* p = str.data();
	size_t plen = str.size();
	while (plen > 0)
	{
		if (mul::parse_line(p, plen, bytes_read, line) && !line.empty())
		{
			line_counter++;
		}
		p += bytes_read;
		plen -= bytes_read;
	}

	assert(line_counter == expected_line_count);
	return 0;
}