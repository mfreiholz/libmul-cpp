#pragma once
#include <string>

#ifdef _WIN32
#include <Windows.h>
#endif

namespace mul {

class ProcessHandle
{
	friend class Process;

public:
	ProcessHandle()
	{
		ZeroMemory(&si, sizeof(si));
		//ZeroMemory(&pi, sizeof(pi));
	}

	ProcessHandle(const ProcessHandle&) = delete;

	ProcessHandle(ProcessHandle&& other) noexcept
	{
		si = std::move(other.si);
		pi = std::move(other.pi);
	}

	ProcessHandle& operator=(const ProcessHandle&) = delete;
	
	~ProcessHandle()
	{
		// Close process and thread handles.
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}

	void wait()
	{
		// Wait until child process exits.
		WaitForSingleObject(pi.hProcess, INFINITE);
	}

	void terminate()
	{
		TerminateProcess(pi.hProcess, 42);
	}

private:
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
};

class Process
{
public:
#ifdef _WIN32
	static ProcessHandle start(const std::string& cmd, bool detach = false)
	{
		ProcessHandle h;
		int flags = 0;
		if (detach)
			flags |= DETACHED_PROCESS;
		flags |= CREATE_NO_WINDOW;

		if (!CreateProcess(
				NULL,
				const_cast<char*>(cmd.c_str()),
				NULL,
				NULL,
				TRUE,
				flags,
				NULL,
				NULL,
				&h.si,
				&h.pi))
		{
			throw std::exception((std::string("CreateProcess failed: ") + std::to_string(GetLastError())).c_str());
		}
		return std::move(h);
	}
#else
	static ProcessHandle start(const std::string& cmd, bool detach = false)
	{
		return {};
	}
#endif
};

} // namespace mul