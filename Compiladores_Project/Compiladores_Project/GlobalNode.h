#pragma once
#include "EEnode_Class.h"
#include "NodeVal.h"
#include "LocalNode.h"
#include <string>

namespace Compiladores_Project
{
	class CGlobalNode
	{
	public:
		CGlobalNode(std::string _symbol, ENODE_CLASS _nclass, int _dimen, std::string _typ);
		~CGlobalNode();

		void SetLocalNode(CLocalNode * n);
		CLocalNode * const GetLocalNode();
		ENODE_CLASS GetNodeClass();
		std::string GetSymbol();

	private:
		std::string symbol;
		ENODE_CLASS nclass;
		CNodeVal * val;
		int dimen;
		std::string typ;
		CLocalNode * localNode;
	};
}