#pragma once

using namespace System;

namespace Compiladores_Project
{
	public enum class ERROR_PHASE
	{
		GLOBAL,
		LEX_ANALYZER,
		SYN_ANALYZER,
		SEM_ANALYZER,
		CODE_GENERATION
	};

#define MAX_UAD_COMPILER_ERRORS 100

	public ref class CErrorModule
	{
	private:
		int numErrors;
		cli::array<String ^> ^ errorsArray;

	public:
		CErrorModule();
		~CErrorModule();

		void ClearErrors();
		bool AddError(ERROR_PHASE errorPhase, int lineNumber, String ^ errorDesc, String ^ errorLine);

		property int NumErrors
		{
			int get()
			{
				return numErrors;
			}
		}

		property int MaxErrors
		{
			int get()
			{
				return MAX_UAD_COMPILER_ERRORS;
			}
		}

		property cli::array<String ^> ^ Errors
		{
			cli::array<String ^> ^ get()
			{
				return errorsArray;
			}
		}
	};
}