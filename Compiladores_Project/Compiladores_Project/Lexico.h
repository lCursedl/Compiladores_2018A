#pragma once

#include "windows.h"
#include "vcclr.h"
#include "ErrorModule.h"
#include "Token.h"

using namespace System;

#include <map>
#include <vector>

namespace Compiladores_Project
{
	enum LexState
	{
		S_START = 0,
		S_PARSING_ID,
		S_PARSING_INT,
		S_PARSING_FLOAT,
		S_PARSING_STRING,
		S_PARSING_LESSTHAN,
		S_PARSING_LESSTHANOREQUAL,
		S_PARSING_GREATERTHAN,
		S_PARSING_GREATERTHANOREQUAL,
		S_PARSING_ASSIGN,
		S_PARSING_EQUAL,
		S_PARSING_NOTEQUAL,
		S_PARSING_OPENPARENTHESIS,
		S_PARSING_CLOSEPARENTHESIS,
		S_PARSING_ARITHMETICOP,
		S_PARSING_LOGICAL_OP_AND,
		S_PARSING_LOGICAL_OP_OR,
		S_PARSING_LOGICAL_OP_NOT,
		S_PARSING_OPENBRACKET,
		S_PARSING_CLOSEBRACKET,
		S_PARSING_OPENCURLYBRACKET,
		S_PARSING_CLOSECURLYBRACKET,
		S_PARSING_SEMICOLON,
		S_PARSING_COMMA,
		S_PARSING_COLON,
		S_PARSING_COMMENT_START,
		S_PARSING_COMMENT_MIDDLE
	};

#define LEX_ERROR_INVALID_CHARACTER			"Invalid character"
#define LEX_ERROR_STRING_NOT_CLOSED			"Literal constant not closed"
#define LEX_ERROR_COMMENT_NOT_CLOSED		"Comment not closed"
#define LEX_ERROR_INVALID_FLOAT				"Invalid floating point number. Digit expected"
#define LEX_ERROR_INVALID_LOGICAL_OP_AND	"Invalid logical 'AND' operator. "
#define LEX_ERROR_INVALID_LOGICAL_OP_OR		"Invalid logical 'OR' operator."
#define LEX_ERROR_INVALID_STATE				"Internal error. Invalid state."

	public class CLexico
	{
	private:
		bool m_Succeeded;
		LexState m_State;

		msclr::gcroot<CErrorModule ^> managedRef_errorsModule;			// REFERENCE TO MANAGED ERRORS MODULE

		std::map<std::string, std::string> m_Keywords;					// KEYWORDS
		std::vector<CToken *> m_Tokens;									// TOKENS

		void addError(int lineNum, const char *desc, const char *line);	// ADD ERROR TO ERRORS MODULE
		void addToken(const char *lex, TYPE_TOKEN type, int lineNum);	// ADD TOKEN TO SYMBOLS TABLE AND TOKENS VECTOR
		void clearTokens();												// FREE MEMORY AND CLEAR TOKENS VECTOR

		bool isAlpha(const char *c) const;
		bool isDigit(const char *c) const;
		bool isSpace(const char *c) const;
		bool isNewLine(const char *c) const;
		bool isArithmeticOp(const char *c) const;
		bool isRelationalOp(const char *c) const;
		bool isLogicalOp(const char *c) const;
		bool isSeparator(const char *c) const;
		bool isGroupingChar(const char *c) const;
		bool isBlockChar(const char *c) const;
		bool isDimensionChar(const char *c) const;
		bool isStringLiteral(const char *c) const;
	public:
		CLexico(CErrorModule ^EModule);
		~CLexico();

		bool ParseCode(const char * src);
		void getTokens(std::vector<CToken *> *tokensVec) const;
		int getNumTokens() const;
		bool Success() const
		{
			return m_Succeeded;
		}
	};
}