// Compiladores_Project.h

#pragma once
#include "windows.h"
#include <vector>
#include "ErrorModule.h"
#include "Lexico.h"
#include "Token.h"
#include "Sintactico.h"
#include "SymTab.h"

using namespace System;

namespace Compiladores_Project {

	public ref class Manager
	{
		// TODO: Add your methods for this class here.
	public:
		Manager();
		~Manager();

		cli::array<String^>^Compile(String ^ program);
		cli::array<String^>^GetAllTokens();
		cli::array<String^>^GetCompilationDetails();

	private:
		CLexico * Lex;
		CSintactico * Syn;
		CErrorModule ^ MError;
		CSymTab * Symtab;
	};
}