#include "CNodeDynamic.h"

CNodeDynamic::CNodeDynamic() 
{
	i_val = 0; 
	pc_parent_node = NULL; 
};
CNodeDynamic::~CNodeDynamic()
{
	v_children.clear();
};
void CNodeDynamic::vSetValue(int iNewVal) { i_val = iNewVal; };
int CNodeDynamic::iGetChildrenNumber() { return v_children.size(); };
void CNodeDynamic::vAddNewChild()
{
	CNodeDynamic* child = new CNodeDynamic();
	child->pc_parent_node =  this;
	v_children.push_back(child);
};

//ex6
void CNodeDynamic::vDeallocFromParent() {
	if (pc_parent_node!=NULL)
	{
		vector<CNodeDynamic*>* parentVector = (&pc_parent_node->v_children);
		for (int i = 0; i < (*parentVector).size(); i++)
		{
			if ((*parentVector).at(i)->i_val == i_val)
			{
				(*parentVector).erase((*parentVector).begin() + i);
			}
		}
		pc_parent_node = NULL;
	}
};
void CNodeDynamic::vAddNewChild(CNodeDynamic* pcChildNode)
{
	pcChildNode->vDeallocFromParent();
	pcChildNode->pc_parent_node = this;
	v_children.push_back(pcChildNode);
};


CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset)
{
	if (iChildOffset < v_children.size())
	{
		return v_children[iChildOffset];
	}
	else
	{
		return NULL;
	}
	
};
void CNodeDynamic::vPrint() 
{
	cout << " " << i_val; 
};
void CNodeDynamic::vPrintAllBelow() 
{
	vPrint();
	for (int i = 0; i < v_children.size(); i++)
	{
		(*v_children[i]).vPrintAllBelow();
	}
};
void CNodeDynamic::vPrintUp()
{
	vPrint();
	if (pc_parent_node != NULL)
	{
		pc_parent_node->vPrintUp();
	}

};