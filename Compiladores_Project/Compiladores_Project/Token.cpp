#include "stdafx.h"
#include "Token.h"


CToken::CToken(std::string lex, TYPE_TOKEN type, int NumLine)
{
}

std::string Compiladores_Project::CToken::getTypeStr()
{
	std::string typeStr = "";
	static const char * EnumStrings[] = {
		"UNDEFINED",
		"ID",
		"INT",
		"FLOAT",
		"STRING",
		"LOGICAL_CONSTANT",
		"KEYWORD",
		"SEPARATOR",
		"RELATIONAL_OPERATOR",
		"ARITHMETIC_OPERATOR",
		"LOGICAL_OPERATOR",
		"LOGICAL_UNARY_OPERATOR",
		"ASSIGN_OPERATOR",
		"GROUPING_OPERATOR",
		"DIMENSION_OPERATOR"
	};
	typeStr = EnumStrings[m_Type];
	return typeStr;
}