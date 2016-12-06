
#include <iostream>
#include <fstream>
#include <string>
#include "Morse_Tree.h"
#include "Binary_Search_Tree.h"
#include "Morse_Code.h"

using namespace std;

int main()
{
	//ifstream input("morse.txt");

	MorseTree My_Tree;

	My_Tree.filereading();
	//My_Tree.fill_map();
	My_Tree.encode("sos");
	//My_Tree.decode("._ . _ ");
	//Binary_Search_Tree<Morse_Code> Morse_T;
	//My_Tree.print();


	system("pause");

	return 0;
}