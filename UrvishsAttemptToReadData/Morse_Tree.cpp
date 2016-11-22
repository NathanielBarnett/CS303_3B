#pragma once

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
        getline(read_morse, readline) // read line by line
        buildBinaryTree(readline.substr(0, 1), code); //send the first letter and the code to the function to create the tree
    }

    return;
}

void MorseTree::buildBinaryTree(const string& letter, const string& code)
{
    MorseTree();

    //Follow through the data
    for (unsigned int i = 0; i < code.length(); i++) //if I don't use unsigned I get an error
    {
        if (dot.find(code[i])) //if its dot, go left
        {
            if (dataNode->left == nullptr) //Check to see if the node exists or not
            {
                dataNode->left = new BTNode<string>("dummy node"); //If it does not exist, create a dummy
            }
            dataNode = dataNode->left; 
        }

        else if (dash.find(code[i])) //of its dash go right
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
