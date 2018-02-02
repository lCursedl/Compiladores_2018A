#include "stdafx.h"
#include "Lexico.h"
#include "Token.h"

#include <algorithm>
#include <iterator>

Compiladores_Project::CLexico::CLexico(CErrorModule ^EModule)
{
	managedRef_errorsModule = EModule;

	m_Keywords.insert(std::make_pair("var", ""));
	m_Keywords.insert(std::make_pair("int", ""));
	m_Keywords.insert(std::make_pair("float", ""));
	m_Keywords.insert(std::make_pair("string", ""));
	m_Keywords.insert(std::make_pair("bool", ""));
	m_Keywords.insert(std::make_pair("function", ""));
	m_Keywords.insert(std::make_pair("procedure", ""));
	m_Keywords.insert(std::make_pair("main", ""));
	m_Keywords.insert(std::make_pair("for", ""));
	m_Keywords.insert(std::make_pair("while", ""));
	m_Keywords.insert(std::make_pair("if", ""));
	m_Keywords.insert(std::make_pair("else", ""));
	m_Keywords.insert(std::make_pair("switch", ""));
	m_Keywords.insert(std::make_pair("default", ""));
	m_Keywords.insert(std::make_pair("print", ""));
	m_Keywords.insert(std::make_pair("read", ""));
	m_Keywords.insert(std::make_pair("return", ""));
}

Compiladores_Project::CLexico::~CLexico(){}

bool Compiladores_Project::CLexico::ParseCode(const char * src)
{
	int currentLineNumber = 1;
	int numCharsInLine = 0;
	int firstLineComment = 0;
	const char *currentChar = src;
	const char * currentLine = src;
	std::string tokenBuffer;
	std::string lineBUfferStr;
	std::string firstCommentLine;
	char lexSrcEof = '\0';
	bool stringNotClosed = false;
	TYPE_TOKEN TokenType = TYPE_TOKEN::UNDEFINED;

	m_Succeeded = true;
	m_State = S_START;
	clearTokens();

	while (*currentChar != lexSrcEof)
	{
		switch (m_State)
		{
		case Compiladores_Project::S_START:
			if (isAlpha(currentChar) || *currentChar == '_')
			{
				tokenBuffer.clear();
				tokenBuffer.append(currentChar, 1);
				m_State = S_PARSING_ID;
				currentChar++;
			}
			else if (isSpace(currentChar))
			{
				if (isNewLine(currentChar) && *currentChar == '\n')
				{
					currentLineNumber++;
					currentLine = currentChar + 1;
				}
				currentChar++;
			}
			break;
		case Compiladores_Project::S_PARSING_ID:
			if (isAlpha(currentChar) || *currentChar == '_' || isDigit(currentChar))
			{
				tokenBuffer.append(currentChar, 1);
				currentChar++;

				if (*currentChar == lexSrcEof)
				{
					if (m_Keywords.find(tokenBuffer) != m_Keywords.end())
					{
						addToken(tokenBuffer.c_str(), TYPE_TOKEN::KEYWORD, currentLineNumber);
					}
					else if (tokenBuffer.compare("true") == 0 || tokenBuffer.compare("false") == 0)
					{
						addToken(tokenBuffer.c_str(), TYPE_TOKEN::LOGICAL_CONSTANT, currentLineNumber);
					}
					else
					{
						addToken(tokenBuffer.c_str(), TYPE_TOKEN::ID, currentLineNumber);
					}
				}
}
			break;
		default:
			break;
		}
	}
}

void Compiladores_Project::CLexico::getTokens(std::vector<CToken *> *tokensVec) const
{
	std::copy(m_Tokens.begin(), m_Tokens.end(), std::back_inserter(*tokensVec));
}

int Compiladores_Project::CLexico::getNumTokens() const
{
	return m_Tokens.size();
}

void Compiladores_Project::CLexico::addError(int lineNum, const char * desc, const char * line)
{
	String ^ strDesc = gcnew String(desc);
	String ^ strLine = gcnew String(line);
	managedRef_errorsModule->addError(Compiladores_Project::ERROR_PHASE::LEX_ANALYZER, lineNum, strDesc, strLine);
	m_Succeeded = false;
}

void Compiladores_Project::CLexico::addToken(const char * lex, TYPE_TOKEN type, int lineNum)
{
	m_Tokens.push_back(new CToken(std::string(lex), type, lineNum));
}

void Compiladores_Project::CLexico::clearTokens()
{
	if (m_Tokens.size() > 0)
	{
		for (int i = 0; i < (int)m_Tokens.size(); i++)
		{
			if (m_Tokens[i] != NULL)
			{
				delete m_Tokens[i];
				m_Tokens[i] = NULL;
			}
		}
		m_Tokens.clear();
	}
}

bool Compiladores_Project::CLexico::isAlpha(const char * c) const
{
	if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z'))
	{
		return true;
	}
	return false;
}

bool Compiladores_Project::CLexico::isDigit(const char * c) const
{
	if (*c >= '0' && *c <= '9')
	{
		return true;
	}
	return false;
}

bool Compiladores_Project::CLexico::isSpace(const char * c) const
{
	if (*c == ' ' || *c == '\t' || isNewLine(c))
	{
		return true;
	}
	return false;
}

bool Compiladores_Project::CLexico::isNewLine(const char * c) const
{
	if (*c == '\n' || *c == '\r')
	{
		return true;
	}
	return false;
}

bool Compiladores_Project::CLexico::isArithmeticOp(const char * c) const
{
	if (*c == '+' || *c == '-' || *c == '*' || *c == '/' || *c == '%' || *c == '^')
	{
		return true;
	}
	return false;
}

bool Compiladores_Project::CLexico::isRelationalOp(const char * c) const
{
	if (*c == '<' || *c == '>' || *c == '=')
	{
		return true;
	}
	return false;
}

bool Compiladores_Project::CLexico::isLogicalOp(const char * c) const
{
	if (*c == '&' || *c == '|' || *c == '!')
	{
		return true;
	}
	return false;
}

bool Compiladores_Project::CLexico::isSeparator(const char * c) const
{
	if (*c == ';' || *c == ',' || *c == ':')
	{
		return true;
	}
	return false;
}

bool Compiladores_Project::CLexico::isGroupingChar(const char * c) const
{
	if (*c == '(' || *c == ')')
	{
		return true;
	}
	return false;
}

bool Compiladores_Project::CLexico::isBlockChar(const char * c) const
{
	if (*c == '{' || *c == '}')
	{
		return true;
	}
	return false;
}

bool Compiladores_Project::CLexico::isDimensionChar(const char * c) const
{
	if (*c == '[' || *c == ']')
	{
		return true;
	}
	return false;
}

bool Compiladores_Project::CLexico::isStringLiteral(const char * c) const
{
	if (*c == '\"')
	{
		return true;
	}
	return false;
}
