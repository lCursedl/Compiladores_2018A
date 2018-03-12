#pragma once
#include <map>
#include <string>
#include "EEnode_Class.h"
#include "GlobalNode.h"

namespace Compiladores_Project
{
	class CSymTab
	{
	public:
		CSymTab();
		~CSymTab();

		bool SymbolExists(std::string symbol, ENODE_CLASS nclass, std::string nprocess_func);
		bool AddSymbol(std::string symbol, ENODE_CLASS nclass, int dimen, std::string typ, std::string nproc_func);

	private:
		std::map<std::string, CGlobalNode*> m_nodes;
	};
}