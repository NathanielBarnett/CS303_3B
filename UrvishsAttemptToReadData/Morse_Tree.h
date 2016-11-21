#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "BTNode.h"
#include "StringTokenizer.h"

using namespace std;

class MorseTree
{
public:

    //MorseTree() { ; }

    MorseTree() 
    {
        dataNode = root;
    };

    void filereading();

    void buildBinaryTree(const string& readline, const string& code);

private:

    string dot = ".";
    string dash = "_";

    BTNode<string> *dataNode = new BTNode<string>("root");
    BTNode<string> *root = dataNode;
};