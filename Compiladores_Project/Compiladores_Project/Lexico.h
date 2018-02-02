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
		S_PARSING_ID
	};

	public class CLexico
	{
	private:
		bool m_Succeeded;
		LexState m_State;
	public:
		CLexico();
		CLexico(CErrorModule EModule);

		~CLexico();

		bool ParseCode(const char * src);
		void getTokens();
		int getNumTokens();
		bool Success();
	};
}