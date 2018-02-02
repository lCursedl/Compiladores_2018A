#include "stdafx.h"
#include "Lexico.h"

using namespace Compiladores_Project;

CLexico::CLexico()
{
}

Compiladores_Project::CLexico::CLexico(CErrorModule EModule)
{
}

CLexico::~CLexico()
{
}

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
	//cleartokens();

	/*while (*currentChar != lexSrcEof)
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
			if (isAlpha(currentChar)) || *currentChar == '_' || isDigit(currentChar))
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
	}*/
}

void Compiladores_Project::CLexico::getTokens()
{
}

int Compiladores_Project::CLexico::getNumTokens()
{
	return 0;
}

bool Compiladores_Project::CLexico::Success()
{
	return false;
}
