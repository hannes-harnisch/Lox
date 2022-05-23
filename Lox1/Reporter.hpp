#pragma once

namespace lox
{
	class Reporter
	{
		bool did_have_error;

	public:
		bool had_error() const;
		void reset_error();
		void report(unsigned line, std::string_view where, std::string_view message);
		void error(unsigned line, std::string_view message);
	};
}
