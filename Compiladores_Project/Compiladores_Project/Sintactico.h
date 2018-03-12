#pragma once

#include "windows.h"
#include "vcclr.h"
#include "ErrorModule.h"
#include "Lexico.h"
#include <string>

using namespace System;

namespace Compiladores_Project
{

#define SYN_ERROR_VAR_GLOBAL_DEFINED	"Global variable alredy defined"
#define SYN_ERROR_VAR_LOCAL_DEFINED		"Local variable alredy defined"
#define SYN_ERROR_VAR_NAME				"Variable cant be named the same as proc/func"
#define SYN_ERROR_PARAM_DEFINED			"Parameter alredy defined"
#define SYN_ERROR_PROC_FUNC_DEFINED		"Proc/func alredy defined"
#define SYN_ERROR_UNEXPECTED_TYPE		"Was expecting x, found y"

	public class CSintactico
	{
	public:
		CSintactico(CErrorModule ^EModule);
		~CSintactico();

	private:
		msclr::gcroot<CErrorModule ^> managedRef_errorsModule;
		

		void addError(int lineNum, const char * desc);
		void addErrorExpected(int n, char * e, char * f);
	};
}