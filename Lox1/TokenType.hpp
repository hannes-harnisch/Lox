#pragma once

namespace lox
{
	enum class TokenType
	{
		LeftParen,
		RightParen,
		LeftBrace,
		RightBrace,
		Comma,
		Dot,
		Minus,
		Plus,
		Semicolon,
		Slash,
		Star,

		LogicalNot,
		Inequal,
		Assign,
		Equal,
		Greater,
		GreaterEqual,
		Less,
		LessEqual,

		Name,
		String,
		Number,

		And,
		Class,
		Else,
		False,
		Fun,
		For,
		If,
		Nil,
		Or,
		Print,
		Return,
		Super,
		This,
		True,
		Var,
		While,

		EndOfFile
	};

	std::string_view to_string(TokenType type);
}
