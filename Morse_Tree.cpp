#pragma once
#include <iostream>
#include "Morse_Tree.h"


void MorseTree::filereading()
{
	string readline;
	string code;

	ifstream read_morse("morse.txt");

	//if file has a problem
	if (!read_morse)
	{
		cout << "Error reading file" << endl;
		//break? probably use exit()?
	}

	//if file is good, start reading it
	while (!read_morse.eof())
	{
		getline(read_morse, readline); // read line by line
		buildBinaryTree(readline.substr(0, 1), readline.substr(1)); //send the first letter and the code to the function to create the tree
	}

	return;
}

void MorseTree::buildBinaryTree(const string& letter, const string& code)
{
	dataNode = root;

	//Follow through the data
	for (unsigned int i = 0; i < code.length(); i++) //if I don't use unsigned I get an error
	{
		if (dot.find(code[i])) //if its dot, go left
		{
			if (dataNode->right == nullptr) //Check to see if the node exists or not
			{
				dataNode->right = new BTNode<string>("dummy node"); //If it does not exist, create a dummy
			}
			
			dataNode = dataNode->right;
		}
		
		else if (dash.find(code[i])) //of its dash go right
		{
			if (dataNode->left == nullptr)
			{
				dataNode->left = new BTNode<string>("dummy node");
			}
			dataNode = dataNode->left;
		}
	}

	dataNode->data = letter; //since the node has to be filled with only the letter and not its data
	return;
}

void MorseTree::print()
{
	cout << root->data << endl;
	cout << root->left->data << endl; // layer 1
	
	cout << root->right->data << endl;
	cout << root->left->right->data << endl;
	cout << root->left->left->data << endl;
	cout << root->right->right->data << endl;
	cout << root->right->right->left->data << endl;
	cout << root->left->left->left->left->data << endl; // layer 4
}