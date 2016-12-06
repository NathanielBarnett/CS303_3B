#pragma once
//Instructor: Prof. Kuhail
//Student Names: Adam Bergman, Urvish Shah, Nathaniel Barnett
//Project 3B
//Date: 12-06-16

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "BTNode.h"


using namespace std;

class MorseTree
{
public:

	//wrapper for printing function
	void print() { BTNode<string>* cursor = root; 
	cout << "In-order traversal of Morse Tree -> ";
							print(cursor);
							cout << endl;}

	//actual printing function to print out an in-order traversal of Morse_Tree
	void print(BTNode<string>*& cursor);

	//constructor
	MorseTree() { ; }

	//function to read in input from a pre-specified file in local directory, and populate tree with data from file
	void filereading();

	//takes in a string letter and a string code, and builds them into the Morse Tree
	void buildBinaryTree(const string& letter, const string& code);

	//using standard Morse encoding for alphabet
	void fill_map();

	//takes in a letter and the associated code and adds them into the map
	void fill_map(const string& letter, const string& code);

	//takes in a string of letters without spaces, and outputs the corresponding code seperated by spaces
	void encode(string letters);

	//takes in a string of dots and dashes with a space inbetween words, and outputs the corresponding letters
	void decode(string code);

private:

	char dot = '.';
	char dash = '_';

	//Node used to trace through tree
	BTNode<string> *dataNode = new BTNode<string>("root");

	//Node used as root of Morse Tree
	BTNode<string> *root = dataNode;

	//map to store values for encoding of strings in Morse
	map<char, string> letter_morse;
};
