#pragma once
#include <queue>
#include <string>

namespace mul
{
	class BufferedLineReader
	{
		std::string _line; // TODO Memory problem: Fix this to maximum size.
		std::queue<std::string> _queue; // TODO Restrict to maximum number of cached lines (RingBuffer?)

	public:
		BufferedLineReader() = default;
		BufferedLineReader(const BufferedLineReader&) = delete;
		BufferedLineReader& operator=(const BufferedLineReader&) = delete;
		~BufferedLineReader() = default;

		void reset()
		{
			while (!_queue.empty())
				_queue.pop();
			_line.clear();
		}

		void append(const char* chars, size_t len)
		{
			for (size_t i = 0; i < len; ++i)
			{
				const auto c = chars[i];
				if (c == '\r' || c == '\n')
				{
					if (_line.size() > 0)
					{
						_queue.push(_line);
						_line = std::string();
					}
				}
				else
				{
					_line += c;
				}
			}
		}

		std::string get()
		{
			if (_queue.empty())
				return std::string();

			const auto str = _queue.front();
			_queue.pop();
			return str;
		}
	};
}