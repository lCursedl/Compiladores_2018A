#pragma once
#include <string>
#include "NodeVal.h"
#include "EEnode_Class.h"

namespace Compiladores_Project
{
	class CLocalNode
	{
	private:

		ENODE_CLASS nclass;
		std::string typ;
		int dimen;
		std::string nproc_func;
		CNodeVal * val;
		CLocalNode * next;

	public:
		CLocalNode(ENODE_CLASS n_class, std::string _typ, int _dimen, std::string _nproc_func);
		~CLocalNode();

		ENODE_CLASS GetNodeClass();
		void SetNext(CLocalNode * n);
		std::string GetNprocFunc();
		CLocalNode * const GetNext();
	};
}