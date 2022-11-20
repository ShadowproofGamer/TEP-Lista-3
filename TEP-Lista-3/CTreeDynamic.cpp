#include "CTreeDynamic.h"
#include "CNodeDynamic.h"


CTreeDynamic::CTreeDynamic() 
{
	pc_root = new CNodeDynamic();
};
CTreeDynamic::~CTreeDynamic() 
{
	delete pc_root;
};
CNodeDynamic* CTreeDynamic::pcGetRoot() { return(pc_root); }
void CTreeDynamic::vPrintTree() {
	pc_root->vPrintAllBelow();
};
bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode)
{
	pcParentNode->vAddNewChild(pcNewChildNode);
	return true;
};
