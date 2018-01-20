// Patel_OrgTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Patel_OrgTree.h"
int _tmain(int argc, _TCHAR* argv[])
{
	OrgTree* theTree = new OrgTree();

	// Test find on a title that's not in the tree
	TREENODEPTR failFind = TREENULLPTR;
	failFind = theTree->find("Mother of Dragons");

	// Test addRoot and hire
	theTree->addRoot("Rock and Roll Expert", "Jim James");
	theTree->hire(theTree->getRoot(), "Caped Crusader", "Batman");
	theTree->hire(theTree->getRoot(), "Strange Robot", "Gir");
	theTree->hire(theTree->getRoot(), "God of Thunder", "Thor");

	// Test find
	TREENODEPTR found = theTree->find("God of Thunder");

	// Test getSize
	cout << "Current number of employees: " << theTree->getSize() << endl;

	// Test leftmostChild and rightSibling
	TREENODEPTR batman = theTree->find("Caped Crusader");
	theTree->hire(batman, "Master of Vengeance", "Arya Stark");
	theTree->hire(batman, "Bad Motherfucker", "Jules Winnfield");
	cout << endl<<endl;
	TREENODEPTR batLeft = theTree->leftmostChild(batman);	// should be Arya
	TREENODEPTR batRight = theTree->rightSibling(batman);	// should be Gir

															// Test printSubTree
	theTree->printSubTree(theTree->getRoot());

	// Hire some more
	TREENODEPTR theBoss = theTree->find("God of Thunder");
	theTree->hire(theBoss, "The Dude", "Jeffery Lebowski");
	theBoss = theTree->find("The Dude");
	theTree->hire(theBoss, "Scruffy-Looking Nerf Herder", "Han Solo");
	theTree->hire(theBoss, "Parks Department Deputy Director", "Leslie Knope");

	// Test adding new root
	theTree->addRoot("Owner", "Bob Belcher");

	// Check whether root and new children were added successfully
	cout << "AFTER ADDING NEW ROOT AND SEVERAL EMPLOYEES:" << endl;
	theTree->printSubTree(theTree->getRoot());
	cout << "Number of employees: " << theTree->getSize() << endl;

	// Test fire
	theTree->fire("Caped Crusader");  // Batman is the leftmost child of the root, has children and has siblings
	cout << "AFTER FIRING BATMAN:" << endl;
	theTree->printSubTree(theTree->getRoot());
	
	cout << "second" << endl;

	cout << "New Number of employees: " << theTree->getSize() << endl;



	return 0;
}
