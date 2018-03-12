#include "stdafx.h"
#include "LocalNode.h"


Compiladores_Project::CLocalNode::CLocalNode(ENODE_CLASS n_class, std::string _typ, int _dimen, std::string _nproc_func)
{
	val = NULL;
	next = NULL;
}

Compiladores_Project::CLocalNode::~CLocalNode()
{
}

ENODE_CLASS Compiladores_Project::CLocalNode::GetNodeClass()
{
	return nclass;
}

void Compiladores_Project::CLocalNode::SetNext(CLocalNode * n)
{
	next = n;
}

std::string Compiladores_Project::CLocalNode::GetNprocFunc()
{
	return nproc_func;
}

Compiladores_Project::CLocalNode * const Compiladores_Project::CLocalNode::GetNext()
{
	return next;
}