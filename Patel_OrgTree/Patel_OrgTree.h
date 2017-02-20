#pragma once
#include <stdio.h>
#include"stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#define TREENODEPTR TreeNode*
#define TREENULLPTR NULL

using namespace std;

//Treenode class
struct TreeNode
{
	string title, name;
	TREENODEPTR leftChild;
	TREENODEPTR rightSiblings;

	/*TreeNode(string title, string name){
	title = title;
	name = name;
	TREENODEPTR leftChild = Tree
	}*/
};

class OrgTree
{
private:

	//create root node, count variable to count number of items in the tree
	TREENODEPTR root;
	int count;
	TREENODEPTR temp = root;


public:

	OrgTree(){
		root = TREENULLPTR;
		count = 0;

	}

	void OrgTree::addRoot(string title, string name){

		if (root == TREENULLPTR){

			root = new TreeNode;
			root->title = title;
			root->name = name;
			root->leftChild = TREENULLPTR;
			root->rightSiblings = TREENULLPTR;
		}
		else{
			TREENODEPTR newNode = new TreeNode();
			newNode->title = title;
			newNode->name = name;
			newNode->leftChild = root;
			newNode->rightSiblings = TREENULLPTR;
			root = newNode;

		}
		count++;

	}

	/*
	this method just return the size of the tree
	*/
	unsigned int OrgTree::getSize(){

		return count;
	}
	/*
	this method return root of the tree
	*/
	TREENODEPTR OrgTree::getRoot() {

		return root;

	}

	/*
	this method return leftmost child of the passed node if it doesn't have left child than return null
	*/
	TREENODEPTR OrgTree::leftmostChild(TREENODEPTR node) {
		if (node->leftChild != TREENULLPTR){
			return node->leftChild;
		}
		else
			return TREENULLPTR;

	}

	/*
	This method return right sibling pointer of the passed node and if it doesn't have right sibling than return null*/
	TREENODEPTR OrgTree::rightSibling(TREENODEPTR node) {

		if (node->rightSiblings != TREENULLPTR){
			return node->rightSiblings;
		}
		else
			TREENULLPTR;
	}

	/*
	This method prints subtree of the passed node of the tree*/
	void OrgTree::printSubTree(TREENODEPTR subTreeRoot){

		//checks if subtree is null or not
		if (subTreeRoot != NULL){
			int tabSpaces = 0;

			//prints title and name of the person
			cout << subTreeRoot->title << ", " << subTreeRoot->name << endl;

			//call printSubHelper method
			printSubTreeHelper(subTreeRoot, tabSpaces);
		}
	}

	/*
	This method prints out subtree*/
	void OrgTree::printSubTreeHelper(TREENODEPTR tempNode, int tabSpaces){
		string tab = "";

		//loop to make spaces at appropriate position
		for (int count = 0; count < tabSpaces; count++)
			tab = tab + "\t";

		//prints title and name of the person
		cout << tab << tempNode->title << ", " << tempNode->name << endl;

		//check if leftchild is null or not 
		if (tempNode->leftChild != NULL)
			//recursively call to go through all left children
			printSubTreeHelper(tempNode->leftChild, tabSpaces + 1);

		//check if rightsibling is null or not 
		if (tempNode->rightSiblings != NULL)
			//recursively call to go through all right siblings 
			printSubTreeHelper(tempNode->rightSiblings, tabSpaces);
	}

	/*
	This method find the title of the person and return pointer to it*/
	TREENODEPTR OrgTree::find(string title) {

		if (root != TREENULLPTR)
			//call another find method
			return find(title, root);

		return TREENULLPTR;
	}

	/*
	This method helps to find correct person's title in the tree*/
	TREENODEPTR OrgTree::find(string Title, TREENODEPTR tempPtr){

		//if tile found then return pointer to it
		if (tempPtr->title == Title)
			return tempPtr;

		TREENODEPTR childPtr = tempPtr->leftChild;
		TREENODEPTR returnPtr = TREENULLPTR;

		//loop to go through all children of the tree
		while (childPtr != TREENULLPTR){
			//recursively call find method with passing left child everytime
			returnPtr = find(Title, childPtr);

			if (returnPtr != TREENULLPTR)
				return returnPtr;
			//traverse through the list
			childPtr = childPtr->rightSiblings;
		}
		return TREENULLPTR;
	}


	/*
	This method hire empolyee in the organization*/
	void OrgTree::hire(TREENODEPTR node, string newTitle, string newName){

		//creates a node to hold data for employee and two pointers
		TREENODEPTR newNode = new TreeNode();
		newNode->title = newTitle;
		newNode->name = newName;
		newNode->leftChild = NULL;
		newNode->rightSiblings = NULL;

		//if node doesn't have left child than simly attach newnode to its left child
		if (node->leftChild == NULL){
			node->leftChild = newNode;
		}
		else{
			//traverse the tree
			TREENODEPTR tempNode = node->leftChild;
			//loop to go through all right siblings until it finds null
			while (tempNode->rightSiblings != TREENULLPTR)
				tempNode = tempNode->rightSiblings;
			//attach new node at the end of the right sibling
			tempNode->rightSiblings = newNode;
		}
		//increament count to keep track of children
		count++;

	}

	/*
	This method fires an employee from the firm*/
	bool OrgTree::fire(string formerTitle){

		if (root->title == formerTitle)
			return false;
		else
			//calls fireHelper method to fire an employee
			fireHelper(formerTitle, root);

	}

	/*this method checks all condition and attach all employees of fired employer to its boss*/
	bool OrgTree::fireHelper(string Title, TREENODEPTR rootRef){

		//create pointers to fire an employer
		TREENODEPTR tempNode = rootRef;
		TREENODEPTR previousNode = tempNode;
		TREENODEPTR currentNode;

		//loop to find employer to all the way left unill null found
		while (tempNode->leftChild != TREENULLPTR){
			TREENODEPTR nextNode = tempNode->leftChild;

			//if employee found than delete get in
			if (nextNode->title == Title)
			{
				if (nextNode->leftChild == TREENULLPTR)
				{
					if (nextNode->rightSiblings != TREENULLPTR){

						//make nextNode's right sibling to previous child's left child
						previousNode->leftChild = nextNode->rightSiblings;
						//fire employee
						delete(nextNode);
					}
					else
						delete(nextNode);
				}
				else
				{
					currentNode = nextNode;
					//loop to go through all right siblings
					while (currentNode->rightSiblings != TREENULLPTR){
						//go through all right siblings until right node found
						currentNode = currentNode->rightSiblings;
					}
					//attach all children to deleted node's parent
					currentNode->rightSiblings = nextNode->leftChild;
					previousNode->leftChild = nextNode->rightSiblings;
					delete(nextNode);
				}
				count--;
				return  true;
			}
			//recursively call method 
			fireHelper(Title, nextNode);
			nextNode = nextNode->rightSiblings;
		}
		while (tempNode->rightSiblings != TREENULLPTR){
			tempNode = tempNode->rightSiblings;
			if (tempNode->title == Title){
				if (tempNode->leftChild == TREENULLPTR)
				{
					if (tempNode->rightSiblings != TREENULLPTR){
						previousNode->rightSiblings = tempNode->rightSiblings;
						delete(tempNode);
						count--;
						return true;
					}
					else
						delete(tempNode);
				}

			}
			fireHelper(Title, tempNode->rightSiblings);
		}

	}
};


