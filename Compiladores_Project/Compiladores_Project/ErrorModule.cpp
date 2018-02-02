#include "stdafx.h"
#include "ErrorModule.h"

Compiladores_Project::CErrorModule::CErrorModule()
{
	numErrors = 0;
	errorsArray = gcnew cli::array<String ^>(MAX_UAD_COMPILER_ERRORS);

	for (int i = 0; i < MAX_UAD_COMPILER_ERRORS; i++)
	{
		errorsArray[i] = gcnew String("");
	}
}

Compiladores_Project::CErrorModule::~CErrorModule(){}

void Compiladores_Project::CErrorModule::ClearErrors()
{
	numErrors = 0;
}

bool Compiladores_Project::CErrorModule::AddError(ERROR_PHASE errorPhase, int lineNumber, String ^ errorDesc, String ^ errorLine)
{
	if (NumErrors < MAX_UAD_COMPILER_ERRORS)
	{
		String ^ errLine = gcnew String("");
		if (errorLine->Length > 20)
		{
			errLine = errorLine->Substring(0, 20);
		}
		else
		{
			errLine = errorLine;
		}

		errorsArray->SetValue(String::Format("<{0}>: \t{1} \t\t{2} \t\t{3}", errorPhase.ToString(), lineNumber, errorDesc, errLine), NumErrors);
		numErrors++;

		return true;
	}
	return false;
}