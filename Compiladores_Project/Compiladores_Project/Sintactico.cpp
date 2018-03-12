#include "stdafx.h"
#include "Sintactico.h"

Compiladores_Project::CSintactico::CSintactico(CErrorModule ^ EModule)
{
	managedRef_errorsModule = EModule;
}

Compiladores_Project::CSintactico::~CSintactico(){}

void Compiladores_Project::CSintactico::addError(int lineNum, const char * desc)
{
	String ^ strDesc = gcnew String(desc);
	String ^ strLine = gcnew String("");
	managedRef_errorsModule->AddError(Compiladores_Project::ERROR_PHASE::SYN_ANALYZER, lineNum, strDesc, strLine);
}

void Compiladores_Project::CSintactico::addErrorExpected(int n, char * e, char * f)
{
	std::string Message1("Was expecting ");
	std::string Expected(e);
	std::string Message2(", was found");
	std::string Found(f);
	std::string Line;
	Line += Message1 + e + Message2 + f;
	addError(n, Line.c_str());
}