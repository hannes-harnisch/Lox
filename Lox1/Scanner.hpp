#pragma once

#include "Reporter.hpp"
#include "Token.hpp"

#include <any>
#include <string>
#include <string_view>
#include <vector>

namespace lox
{
	class Scanner
	{
		Reporter&		   reporter;
		std::string_view   source;
		std::vector<Token> tokens;
		unsigned		   start   = 0;
		unsigned		   current = 0;
		unsigned		   line	   = 1;

	public:
		Scanner(Reporter& reporter, std::string_view source);

		std::vector<Token> scan_tokens();

	private:
		void scan_token();
		void add_token(TokenType type);
		void add_token(TokenType type, std::any literal);
		bool match(char expected);
		char peek() const;
		char advance();
		bool is_at_end() const;
	};
}
