#include "CNodeStatic.h"
#include <iostream>

CNodeStatic::CNodeStatic() {
	i_val = 0; 
	pc_parent_node = NULL; 
};
CNodeStatic::~CNodeStatic() {
	/*
		for (int i = 0; i < v_children.size(); i++)
	{
		delete &v_children[i];
	}
	delete this;
	//*/
	v_children.clear();
};
void CNodeStatic::vSetValue(int iNewVal) { i_val = iNewVal; };
int CNodeStatic::iGetChildrenNumber() { return(v_children.size()); };
void CNodeStatic::vAddNewChild()
{
	CNodeStatic child = CNodeStatic();

	//ex3
	child.pc_parent_node = this;
	//

	v_children.push_back(child);
};
CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset)
{
	if (iChildOffset<v_children.size())
	{
		return &v_children[iChildOffset];
	}
	else
	{
		return NULL;
	}
};
void CNodeStatic::vPrint() 
{
	std::cout << " " << i_val; 
};
void CNodeStatic::vPrintAllBelow()
{
	vPrint();
	for (int i = 0; i < v_children.size(); i++)
	{
		v_children[i].vPrintAllBelow();
	}
};

//ex3
void CNodeStatic::vPrintUp()
{
	vPrint();
	if (pc_parent_node != NULL)
	{
		pc_parent_node->vPrintUp();
	}
	
};

//ex6
void CNodeStatic::vDeallocFromParent() {
	if (pc_parent_node != NULL)
	{
		//cout << "parent not null Static" << endl;
		vector<CNodeStatic>* parentVector = (&pc_parent_node->v_children);
		for (int i = 0; i < (*parentVector).size(); i++)
		{
			if ((*parentVector).at(i).i_val == i_val)
			{
				//cout << "myself found" << endl;
				(*parentVector).erase((*parentVector).begin() + i);
			}
		}
		pc_parent_node = NULL;
	}
};

void CNodeStatic::vAddNewChild(CNodeStatic* pcChildNode)
{
	CNodeStatic child = (*pcChildNode);
	child.pc_parent_node = this;
	v_children.push_back(child);
	pcChildNode->vDeallocFromParent();
	
	
};

