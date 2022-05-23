#include "PCH.hpp"

#include "Scanner.hpp"

namespace lox
{
	Scanner::Scanner(Reporter& reporter, std::string_view source) : reporter(reporter), source(source)
	{}

	std::vector<Token> Scanner::scan_tokens()
	{
		while(!is_at_end())
		{
			start = current;
			scan_token();
		}

		tokens.emplace_back(TokenType::EndOfFile, "", std::any(), line);
		return std::move(tokens);
	}

	void Scanner::scan_token()
	{
		switch(advance())
		{
			using enum TokenType;
			case '(': add_token(LeftParen); break;
			case ')': add_token(RightParen); break;
			case '{': add_token(LeftBrace); break;
			case '}': add_token(RightBrace); break;
			case ',': add_token(Comma); break;
			case '.': add_token(Dot); break;
			case '-': add_token(Minus); break;
			case '+': add_token(Plus); break;
			case ';': add_token(Semicolon); break;
			case '*': add_token(Star); break;
			case '!': add_token(match('=') ? Inequal : LogicalNot); break;
			case '=': add_token(match('=') ? Equal : Assign); break;
			case '<': add_token(match('=') ? LessEqual : Less); break;
			case '>': add_token(match('=') ? GreaterEqual : Greater); break;
			case '/':
			{
				if(match('/'))
				{
					while(peek() != '\n' && !is_at_end())
						advance();
				}
				else
					add_token(Slash);
				break;
			}
			case ' ':
			case '\r':
			case '\t': break;
			case '\n': ++line; break;
			default: reporter.error(line, "unexpected character"); break;
		}
	}

	void Scanner::add_token(TokenType type)
	{
		add_token(type, {});
	}

	void Scanner::add_token(TokenType type, std::any literal)
	{
		auto text = source.substr(start, current);
		tokens.emplace_back(type, text, std::move(literal), line);
	}

	bool Scanner::match(char expected)
	{
		if(is_at_end())
			return false;

		if(source[current] != expected)
			return false;

		++current;
		return true;
	}

	char Scanner::peek() const
	{
		if(is_at_end())
			return '\0';
		else
			return source[current];
	}

	char Scanner::advance()
	{
		return source[current++];
	}

	bool Scanner::is_at_end() const
	{
		return current >= source.size();
	}
}
