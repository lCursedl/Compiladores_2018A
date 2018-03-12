#include "stdafx.h"
#include "UADCompiler_LexAnalyzer.h"
#include "UADCompiler_Token.h"

#include <algorithm>
#include <iterator>

/*
*/
UADCompilerCore::LexAnalyzer::LexAnalyzer(ErrorsModule ^ errorsModule)
{
	managedRef_errorsModule = errorsModule;

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

/*
*/
UADCompilerCore::LexAnalyzer::~LexAnalyzer()
{
}

/*
*/
bool UADCompilerCore::LexAnalyzer::parseSourceCode(const char * sourceCode)
{

}

/*
*/
int UADCompilerCore::LexAnalyzer::getNumTokens() const
{
	return m_Tokens.size();
}

/*
*/
 void UADCompilerCore::LexAnalyzer::getTokens(std::vector<Token *> *tokensVec) const
{
	std::copy(m_Tokens.begin(), m_Tokens.end(), std::back_inserter(*tokensVec));
}

/*
*/
void UADCompilerCore::LexAnalyzer::addError(int lineNum, const char *desc, const char *line)
{
	String ^ strDesc = gcnew String(desc);
	String ^ strLine = gcnew String(line);
	managedRef_errorsModule->addError(UADCompilerCore::ERROR_PHASE::LEX_ANALYZER, lineNum, strDesc, strLine);
	m_Succeeded = false;
}

/*
*/
void UADCompilerCore::LexAnalyzer::addToken(const char * lex, TOKEN_TYPE type, int lineNum)
{
	m_Tokens.push_back(new Token(std::string(lex), type, lineNum));
}

/*
*/
void UADCompilerCore::LexAnalyzer::clearTokens()
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

/*
*/
bool UADCompilerCore::LexAnalyzer::isAlpha(const char * c) const
{
	if ((*c >= 'a' && *c <= 'z') || (*c >= 'A' && *c <= 'Z'))
	{
		return true;
	}

	return false;
}

/*
*/
bool UADCompilerCore::LexAnalyzer::isDigit(const char * c) const
{
	if (*c >= '0' && *c <= '9')
	{
		return true;
	}

	return false;
}

/*
*/
bool UADCompilerCore::LexAnalyzer::isSpace(const char * c) const
{
	if (*c == ' ' || *c == '\t' || isNewLine(c) )
	{
		return true;
	}

	return false;
}

/*
*/
bool UADCompilerCore::LexAnalyzer::isNewLine(const char * c) const
{
	if (*c == '\n' || *c == '\r')
	{
		return true;
	}

	return false;
}

/*
*/
bool UADCompilerCore::LexAnalyzer::isArithmeticOp(const char * c) const
{
	if (*c == '+' || *c == '-' || *c == '*' || *c == '/' || *c == '%' || *c == '^')
	{
		return true;
	}

	return false;
}

/*
*/
bool UADCompilerCore::LexAnalyzer::isRelationalOp(const char * c) const
{
	if (*c == '<' || *c == '>' || *c == '=')
	{
		return true;
	}

	return false;
}

/*
*/
bool UADCompilerCore::LexAnalyzer::isLogicalOp(const char * c) const
{
	if (*c == '&' || *c == '|' || *c == '!')
	{
		return true;
	}

	return false;
}

/*
*/
bool UADCompilerCore::LexAnalyzer::isSeparator(const char * c) const
{
	if (*c == ';' || *c == ',' || *c == ':')
	{
		return true;
	}

	return false;
}

/*
*/
bool UADCompilerCore::LexAnalyzer::isGroupingChar(const char * c) const
{
	if (*c == '(' || *c == ')')
	{
		return true;
	}

	return false;
}

bool UADCompilerCore::LexAnalyzer::isBlockChar(const char * c) const
{
	if (*c == '{' || *c == '}')
	{
		return true;
	}

	return false;
}

/*
*/
bool UADCompilerCore::LexAnalyzer::isDimensionChar(const char * c) const
{
	if (*c == '[' || *c == ']')
	{
		return true;
	}

	return false;
}

/*
*/
bool UADCompilerCore::LexAnalyzer::isStringLiteral(const char * c) const
{
	if (*c == '\"')
	{
		return true;
	}

	return false;
}
