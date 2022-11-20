#include "CTreeStatic.h"

//ex4
CTreeStatic::CTreeStatic() 
{
	c_root = CNodeStatic();
};
CTreeStatic::~CTreeStatic(){};
CNodeStatic* CTreeStatic::pcGetRoot() 
{
	return(&c_root); 
}
void CTreeStatic::vPrintTree()
{
	pcGetRoot()->vPrintAllBelow();
};
bool CTreeStatic::bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode)
{
	pcParentNode->vAddNewChild(pcNewChildNode);
	return true;
};
