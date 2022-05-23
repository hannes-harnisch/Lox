#include "PCH.hpp"

#include "TokenType.hpp"

#define STR(enumerator)                                                                                                        \
	case TokenType::enumerator: return #enumerator;

namespace lox
{
	std::string_view to_string(TokenType type)
	{
		switch(type)
		{
			STR(LeftParen)
			STR(RightParen)
			STR(LeftBrace)
			STR(RightBrace)
			STR(Comma)
			STR(Dot)
			STR(Minus)
			STR(Plus)
			STR(Semicolon)
			STR(Slash)
			STR(Star)
			STR(LogicalNot)
			STR(Inequal)
			STR(Assign)
			STR(Equal)
			STR(Greater)
			STR(GreaterEqual)
			STR(Less)
			STR(LessEqual)
			STR(Name)
			STR(String)
			STR(Number)
			STR(And)
			STR(Class)
			STR(Else)
			STR(False)
			STR(Fun)
			STR(For)
			STR(If)
			STR(Nil)
			STR(Or)
			STR(Print)
			STR(Return)
			STR(Super)
			STR(This)
			STR(True)
			STR(Var)
			STR(While)
			STR(EndOfFile)
		}
		throw std::invalid_argument("Unknown token type value");
	}
}
