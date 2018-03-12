#include "stdafx.h"
#include "GlobalNode.h"

Compiladores_Project::CGlobalNode::CGlobalNode(std::string _symbol, ENODE_CLASS _nclass, int _dimen, std::string _typ)
{
	val = NULL;
	localNode = NULL;
}

Compiladores_Project::CGlobalNode::~CGlobalNode()
{
}

void Compiladores_Project::CGlobalNode::SetLocalNode(CLocalNode * n)
{
	if (localNode == nullptr)
	{
		localNode = n;
	}
	else
	{
		CLocalNode * tmp;
		tmp = localNode;
		localNode = n;
		n->SetNext(tmp);
	}
}

Compiladores_Project::CLocalNode * const Compiladores_Project::CGlobalNode::GetLocalNode()
{
	return localNode;
}

ENODE_CLASS Compiladores_Project::CGlobalNode::GetNodeClass()
{
	return nclass;
}

std::string Compiladores_Project::CGlobalNode::GetSymbol()
{
	return std::string();
}