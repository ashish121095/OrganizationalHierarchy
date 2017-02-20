// Patel_OrgTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Patel_OrgTree.h"
int _tmain(int argc, _TCHAR* argv[])
{
	ofstream file;
	file.open("inutfile.txt");
	OrgTree tree;
	
	//tree.printSubTree;
	/*TREENODEPTR root = new TreeNode();
	root->title = "root title";
	root->name = "root name";
	*/
	tree.addRoot("Root Title", "Root Name");
	TREENODEPTR node1 = tree.getRoot();
	tree.hire(node1, "node1 Title1", "node1 Name1");
	tree.hire(node1, "node2 Title2", "node2 Name2");
	tree.hire(node1, "node3 Title3", "node3 Name3");
	tree.hire(node1, "node4 Title4", "node4 Name4");
	tree.hire(node1, "node5 Title5", "node5 Name5");
	tree.hire(node1, "node6 Title6", "node6 Name6");

	//tree.find("node1 Title4");

	tree.printSubTree(node1);
	tree.fire("node4 Title4");
	tree.printSubTree(node1);
	
	cout << "ye" << endl;

	system("pause");
	return 0;
}