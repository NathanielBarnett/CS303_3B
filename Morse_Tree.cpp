#pragma once
//FANCY HEADER
//FANCY HEADER
//FANCY HEADER


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
		return;
	}

	//if file is good, start reading it
	while (!read_morse.eof())
	{
		getline(read_morse, readline); // read line by line
		fill_map(readline.substr(0, 1), readline.substr(1));
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
		if (code[i] == dot) //if its dot, go left
		{
			if (dataNode->left == nullptr) //Check to see if the node exists or not
			{
				dataNode->left = new BTNode<string>("dummy node"); //If it does not exist, create a dummy
			}
			
			dataNode = dataNode->left;
		}
		
		else if (code[i] == dash) //of its dash go right
		{
			if (dataNode->right == nullptr)
			{
				dataNode->right = new BTNode<string>("dummy node");
			}
			dataNode = dataNode->right;
		}
	}

	dataNode->data = letter; //since the node has to be filled with only the letter and not its data
	return;
}

void MorseTree::fill_map()
{
	
	letter_morse['a'] = "._";
	letter_morse['b'] = "_...";
	letter_morse['c'] = "_._.";
	letter_morse['d'] = "_..";
	letter_morse['e'] = ".";
	letter_morse['f'] = ".._.";
	letter_morse['g'] = "__.";
	letter_morse['h'] = "....";
	letter_morse['i'] = "..";
	letter_morse['j'] = ".___";
	letter_morse['k'] = "_._";
	letter_morse['l'] = "._..";
	letter_morse['m'] = "__";
	letter_morse['n'] = "_.";
	letter_morse['o'] = "___";
	letter_morse['p'] = ".__.";
	letter_morse['q'] = "__._";
	letter_morse['r'] = "._.";
	letter_morse['s'] = "...";
	letter_morse['t'] = "_";
	letter_morse['u'] = ".._";
	letter_morse['v'] = "..._";
	letter_morse['w'] = ".__";
	letter_morse['x'] = "_.._";
	letter_morse['y'] = "_.__";
	letter_morse['z'] = "__..";
}

void MorseTree::fill_map(const string& letter, const string& code)
{
	char temp_letter = letter[0];	// take first character of string and use as key for map
	letter_morse[temp_letter] = code;	// insert key and value into map, if not already present
}

void MorseTree::encode(string letters)
{
	//while string is not empty, output the morse code representation of each character, 
	//inserting a space after each letter
	while (letters.length() != 0)
	{
		cout << letter_morse.find(letters[0])->second << " ";
		letters = letters.substr(1);
	}
}
void MorseTree::decode(string code)
{
	dataNode = root;

	//Follow through the data
	for (unsigned int i = 0; i < code.length(); i++) //if I don't use unsigned I get an error
	{
		if (code[i] == dot ) //if its dot, go left
		{
			dataNode = dataNode->left;
		}
		else if (code[i] == dash) //if its dash go right
		{
			dataNode = dataNode->right;
		}
		else //Its a space
		{
			cout << dataNode->data << " "; //Print the letter
			dataNode = root;
		}
	}
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
