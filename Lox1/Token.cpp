#include "PCH.hpp"

#include "Token.hpp"

namespace lox
{
	Token::Token(TokenType type, std::string_view lexeme, std::any literal, unsigned line) :
		type(type), lexeme(lexeme), literal(std::move(literal)), line(line)
	{}

	std::string Token::to_string() const
	{
		return std::format("{} {}", lox::to_string(type), lexeme);
	}
}
