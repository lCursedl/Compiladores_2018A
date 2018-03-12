#include "stdafx.h"
#include "SymTab.h"

Compiladores_Project::CSymTab::CSymTab()
{
}

Compiladores_Project::CSymTab::~CSymTab()
{
}

bool Compiladores_Project::CSymTab::SymbolExists(std::string symbol, ENODE_CLASS nclass, std::string nprocess_func)
{
	if (nclass == GLOBAL_VAR || nclass == PROCDR || nclass == FUNC)
	{
		if (m_nodes.find(symbol) != m_nodes.end())
		{
			return true;
		}
	}
	else if (nclass == PARAM || nclass == LOCAL_VAR)
	{
		auto it = m_nodes.find(symbol);
		if (it != m_nodes.end())
		{
			CGlobalNode * gnode = it->second;
			if (gnode != nullptr)
			{
				CLocalNode * lnode = gnode->GetLocalNode();
				while (lnode != nullptr)
				{
					if (lnode->GetNodeClass() == nclass && lnode->GetNprocFunc().compare(nprocess_func) == 0)
					{
						return true;
					}
					lnode = lnode->GetNext();
				}
			}
		}
		return false;
	}
}

bool Compiladores_Project::CSymTab::AddSymbol(std::string symbol, ENODE_CLASS nclass, int dimen, std::string typ, std::string nproc_func)
{
	if (!SymbolExists(symbol, nclass, nproc_func))
	{
		if (nclass == GLOBAL_VAR || nclass == PROCDR || nclass == FUNC)
		{
			m_nodes.insert(std::make_pair(symbol, new CGlobalNode(symbol, nclass, dimen, typ)));
		}
	}
	else if(nclass == PARAM || nclass == LOCAL_VAR)
	{
		CLocalNode * lnode = new CLocalNode(nclass, typ, dimen, nproc_func);
		auto it = m_nodes.find(symbol);
		if (it != m_nodes.end())
		{
			CGlobalNode * gnode = it->second;
			gnode->SetLocalNode(lnode);
		}
		else
		{
			CGlobalNode * gnodde = new CGlobalNode(symbol, UNDEFINED, dimen, typ);
			gnodde->SetLocalNode(lnode);
		}
		return true;
	}
	return false;
}