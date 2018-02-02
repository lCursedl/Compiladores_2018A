// This is the main DLL file.

#include "stdafx.h"

#include "Compiladores_Project.h"

using namespace Compiladores_Project;

Manager::Manager()
{
	MError = gcnew CErrorModule();
	Lex = new CLexico(MError);
}

Manager::~Manager()
{
	delete Lex;
}

cli::array<String^>^ Compiladores_Project::Manager::Compile(String ^ program)
{
	int numPhasesFailed = 0;
	cli::array<String^>^CompilationDetails;

	if (MError && Lex == NULL)
	{
		
	}
	else
	{
		if (!MError)
		{
			CompilationDetails = gcnew cli::array<String^>(1);
			CompilationDetails[0] = gcnew String("Error on Error Module");
			return CompilationDetails;
		}
		else if (!Lex)
		{
			CompilationDetails = gcnew cli::array<String^>(1);
			CompilationDetails[0] = gcnew String("Error on Lex Analyzer");
			return CompilationDetails;
		}
	}	

	Lex->ParseCode((const char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(program).ToPointer());
	return CompilationDetails;
}

cli::array<String^>^ Compiladores_Project::Manager::GetAllTokens()
{
	cli::array <String^>^AllTokens;

	if (Lex->getNumTokens() > 0)
	{
		std::vector<CToken*> VecTokens;
		
	}
	// TODO: insert return statement here
}

cli::array<String^>^ Compiladores_Project::Manager::GetCompilationDetails()
{
	// TODO: insert return statement here
	int numErrorLines = 0;
	cli::array<String^>^CDetails;
	if (Lex->Success())
	{
		CDetails = gcnew cli::array<String ^>(1);
		CDetails[0] = gcnew String("Compile: Succeeded");
		return CDetails;
	}
	else
	{
		numErrorLines = MError->NumErrors + 3;
		CDetails = gcnew cli::array<String ^>(numErrorLines);
		for (int i = 0; i < numErrorLines; i++)
		{
			CDetails[i] = gcnew String("");
		}
		CDetails[0] = String::Format("Compilation phase \tLine number \tDescription \t\t\tLine");
		CDetails[1] = String::Format("--------------------------------------------------------");

		//cli::array<String^>^AllErrors = MError->Errors;
		for (int i = 2; i < numErrorLines; i++)
		{
			//CDetails[i] = AllErrors[i - 2];
		}

		CDetails[numErrorLines - 1] = String::Format("Compile: Failed, MError->NumErrors");

		return CDetails;
	}
}