#include "Process.hpp"
#include <thread>
#include <chrono>

int main(int argc, char** argv)
{
	const auto detach = false;
	auto h = mul::Process::start("python.exe \"D:\\Sources\\python-scripts\\test_process\\main.py\"", detach);
	h.wait();
	return 0;
}