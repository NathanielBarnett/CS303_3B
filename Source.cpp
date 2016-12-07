//Instructor: Prof. Kuhail
//Student Names: Adam Bergman, Urvish Shah, Nathaniel Barnett
//Project 3B
//Date: 12-06-16

#include "Morse_Tree.h"


using namespace std;

int main()
{
	//ifstream input("morse.txt");

	MorseTree My_Tree;

	My_Tree.filereading();

	My_Tree.encode("sos");

	My_Tree.decode("._ . _ ");

	My_Tree.print();


	system("pause");

	return 0;
}
