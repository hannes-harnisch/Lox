#include "PCH.hpp"

#include "Reporter.hpp"

namespace lox
{
	bool Reporter::had_error() const
	{
		return did_have_error;
	}

	void Reporter::reset_error()
	{
		did_have_error = false;
	}

	void Reporter::report(unsigned line, std::string_view where, std::string_view message)
	{
		std::cerr << "[line " << line << "] Error" << where << ": " << message;
		did_have_error = true;
	}

	void Reporter::error(unsigned line, std::string_view message)
	{
		report(line, "", message);
	}
}
