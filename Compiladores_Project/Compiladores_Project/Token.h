#pragma once
#include <string>

namespace Compiladores_Project
{
	enum TYPE_TOKEN
	{
		UNDEFINED = 0,
		ID,
		INT,
		FLOAT,
		STRING,
		LOGICAL_CONSTANT,
		KEYWORD,
		SEPARATOR,
		RELATIONAL_OPERATOR,
		ARITHMETIC_OPERATOR,
		LOGICAL_OPERATOR,
		LOGICAL_UNARY_OPERATOR,
		ASSIGN_OPERATOR,
		GROUPING_OPERATOR,
		DIMENSION_OPERATOR
	};

	class CToken
	{
	private:
		std::string m_Lex;
		TYPE_TOKEN m_Type;
		int m_NumLine;
	public:
		CToken(std::string lex, TYPE_TOKEN type, int NumLine)
		{}

		std::string getLex() const { return m_Lex; }
		std::string getTypeStr();
		TYPE_TOKEN getType() const { return m_Type; }
		int getNumerLine() const { return m_NumLine; }
	};
}