#include "Tests.h"

void v_tree_test()
{
	//ex2
	std::cout << std::endl << "ex2:" << std::endl;

	CNodeStatic c_root;
	c_root.vAddNewChild();
	c_root.vAddNewChild();
	c_root.pcGetChild(0)->vSetValue(1);
	c_root.pcGetChild(1)->vSetValue(2);
	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);
	c_root.vPrintAllBelow();
	//

	//ex3
	std::cout << std::endl << "ex3:" << std::endl;

	c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();

	//ex4 test
	std::cout << std::endl << "ex4 test:" << std::endl;
	CTreeStatic c_tree;
	(*c_tree.pcGetRoot()).vAddNewChild();
	(*c_tree.pcGetRoot()).vAddNewChild();
	(*c_tree.pcGetRoot()).pcGetChild(0)->vSetValue(1);
	(*c_tree.pcGetRoot()).pcGetChild(1)->vSetValue(2);
	(*c_tree.pcGetRoot()).pcGetChild(0)->vAddNewChild();
	(*c_tree.pcGetRoot()).pcGetChild(0)->vAddNewChild();
	(*c_tree.pcGetRoot()).pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	(*c_tree.pcGetRoot()).pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	(*c_tree.pcGetRoot()).pcGetChild(1)->vAddNewChild();
	(*c_tree.pcGetRoot()).pcGetChild(1)->vAddNewChild();
	(*c_tree.pcGetRoot()).pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	(*c_tree.pcGetRoot()).pcGetChild(1)->pcGetChild(1)->vSetValue(22);
	c_tree.vPrintTree();

	//ex5 test
	std::cout << std::endl << "ex5 test:" << std::endl;
	CTreeDynamic c_tree2;
	(*c_tree2.pcGetRoot()).vAddNewChild();
	(*c_tree2.pcGetRoot()).vAddNewChild();
	(*c_tree2.pcGetRoot()).pcGetChild(0)->vSetValue(1);
	(*c_tree2.pcGetRoot()).pcGetChild(1)->vSetValue(2);
	(*c_tree2.pcGetRoot()).pcGetChild(0)->vAddNewChild();
	(*c_tree2.pcGetRoot()).pcGetChild(0)->vAddNewChild();
	(*c_tree2.pcGetRoot()).pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	(*c_tree2.pcGetRoot()).pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	(*c_tree2.pcGetRoot()).pcGetChild(1)->vAddNewChild();
	(*c_tree2.pcGetRoot()).pcGetChild(1)->vAddNewChild();
	(*c_tree2.pcGetRoot()).pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	(*c_tree2.pcGetRoot()).pcGetChild(1)->pcGetChild(1)->vSetValue(22);
	c_tree2.vPrintTree();

}

//ex6
void v_subset_move_test() 
{
	CTreeStatic c_tree1;
	CTreeStatic c_tree2;
	CTreeDynamic c_tree11;
	CTreeDynamic c_tree22;

	//filling c_tree1
	for (int i = 0; i < 3; i++)
	{
		c_tree1.pcGetRoot()->vAddNewChild();
		c_tree1.pcGetRoot()->pcGetChild(i)->vSetValue(i + 1);
	}
	c_tree1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
	c_tree1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

	//filling c_tree2
	c_tree2.pcGetRoot()->vSetValue(50);
	c_tree2.pcGetRoot()->vAddNewChild();
	c_tree2.pcGetRoot()->vAddNewChild();

	c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
	c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
	c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
	c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);
	c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);


	c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(55);

	//filling c_tree11
	for (int i = 0; i < 3; i++)
	{
		c_tree11.pcGetRoot()->vAddNewChild();
		c_tree11.pcGetRoot()->pcGetChild(i)->vSetValue(i + 1);
	}
	c_tree11.pcGetRoot()->pcGetChild(2)->vAddNewChild();
	c_tree11.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

	//filling c_tree22
	c_tree22.pcGetRoot()->vSetValue(50);
	c_tree22.pcGetRoot()->vAddNewChild();
	c_tree22.pcGetRoot()->vAddNewChild();

	c_tree22.pcGetRoot()->pcGetChild(0)->vSetValue(54);
	c_tree22.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree22.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree22.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
	c_tree22.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
	c_tree22.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);
	c_tree22.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);


	c_tree22.pcGetRoot()->pcGetChild(1)->vSetValue(55);

	//checking tree format
	cout << endl << endl << "ex6 checking trees before move:" << endl;
	c_tree1.vPrintTree();
	cout << endl;
	c_tree2.vPrintTree();
	cout << endl;
	c_tree11.vPrintTree();
	cout << endl;
	c_tree22.vPrintTree();
	cout << endl;

	//testing dealoc static
	/*
	cout << endl << "Testing pre-dealoc Static: " << endl;
	CNodeStatic* c_Node1 = c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0);
	c_Node1->vPrint();
	c_Node1->vDeallocFromParent();
	cout << endl << "Testing dealoc Static: " << endl;
	c_tree2.vPrintTree();
	cout << endl;
	c_Node1->vPrintUp();
	cout << endl;
	c_Node1->vPrintAllBelow();
	
	//*/


	/*
	cout << endl << "Testing pre-dealoc Dynamic: " << endl;
	CNodeDynamic* c_Node11 = c_tree22.pcGetRoot()->pcGetChild(0)->pcGetChild(0);
	c_Node11->vPrint();
	c_Node11->vDeallocFromParent();
	cout << endl << "Testing dealoc Dynamic: " << endl;
	c_tree22.vPrintTree();
	cout << endl;
	c_Node11->vPrintUp();
	cout << endl;
	c_Node11->vPrintAllBelow();
	//*/

	/*
	cout << endl << "Testing vAddChildren(&) Dynamic: ";
	c_tree11.pcGetRoot()->pcGetChild(2)->vAddNewChild(c_tree22.pcGetRoot()->pcGetChild(0));
	cout << endl << "tree11 Dynamic: " << endl;
	c_tree11.vPrintTree();
	cout << endl << "tree22 Dynamic: " << endl;
	c_tree22.vPrintTree();

	//*/

	//testing Static bMoveSubtree
	/*
	c_tree1.bMoveSubtree(c_tree1.pcGetRoot()->pcGetChild(2), c_tree2.pcGetRoot()->pcGetChild(0));
	c_tree1.vPrintTree();
	c_tree2.vPrintTree();
	//*/


	//testing Dynamic bMoveSubtree
	///*
	cout << "testing move subtree Dynamic:" << endl;
	c_tree11.bMoveSubtree(c_tree11.pcGetRoot()->pcGetChild(2), c_tree22.pcGetRoot()->pcGetChild(0));
	cout << "tree11 Dynamic:" << endl;
	c_tree11.vPrintTree();
	cout << endl << "tree22 Dynamic:" << endl;
	c_tree22.vPrintTree();
	//*/

};