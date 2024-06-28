#pragma once
#include <inttypes.h>
#include <string>

namespace mul
{
	/**
	 * Parses `data` until the end of line.
	 * Writes parsed data into `line`.
	 * Returns `true` if EOL occured, otherwise returns `false`.
	*/
	bool parse_line(const char* data, size_t len, size_t& bytes_parsed, std::string& line)
	{
		bytes_parsed = 0;
		size_t line_length = 0;

		for (size_t i = 0; i < len; i++)
		{
			const auto c = data[i];
			bytes_parsed++;

			if (c == '\r' || c == '\n')
			{
				if (line_length > 0)
				{
					return true;
				}
			}
			else
			{
				line += c;
				line_length++;
			}
		}
		return false;
	}
}