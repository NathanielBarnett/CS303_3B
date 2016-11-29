#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "BTNode.h"
#include "String_Tokenizer.h"

using namespace std;

class MorseTree
{
public:

	void print();
	MorseTree() { ; }

	void filereading();

	void buildBinaryTree(const string& readline, const string& code);

	void fill_map();
	void encode(string letters);
	void decode(string code);

private:

	char dot = '.';
	char dash = '_';

	BTNode<string> *dataNode = new BTNode<string>("root");
	BTNode<string> *root = dataNode;

	map<char, string> letter_morse;
};
