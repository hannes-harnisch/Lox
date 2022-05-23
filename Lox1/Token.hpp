#pragma once

#include "TokenType.hpp"

#include <string>

namespace lox
{
	class Token
	{
		TokenType	type;
		std::string lexeme;
		std::any	literal;
		unsigned	line;

	public:
		Token(TokenType type, std::string_view lexeme, std::any literal, unsigned line);

		std::string to_string() const;
	};
}
