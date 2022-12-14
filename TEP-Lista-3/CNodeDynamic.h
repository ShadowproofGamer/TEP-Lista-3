#pragma once
#include <vector>
#include <iostream>
using namespace std;


class CNodeDynamic
{
public:
	CNodeDynamic();
	~CNodeDynamic();
	void vSetValue(int iNewVal);
	int iGetChildrenNumber();
	void vAddNewChild();

	CNodeDynamic* pcGetChild(int iChildOffset);
	void vPrint();
	void vPrintAllBelow();
	void vPrintUp();
	//ex6
	void vAddNewChild(CNodeDynamic* pcNewChild);
	void vDeallocFromParent();
private:
	vector<CNodeDynamic*> v_children;
	CNodeDynamic* pc_parent_node;
	int i_val;
};