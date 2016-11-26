#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <map>

#include "BTNode.h"
#include "StringTokenizer.h"

using namespace std;

class MorseTree
{
public:

    MorseTree() {};

    void filereading();
    void buildBinaryTree(const string& readline, const string& code);

    void fill_map();
    void encode(string letters);
    void decode(string code);

private:

    string dot = ".";
    string dash = "_";

    BTNode<string> *dataNode = new BTNode<string>("root");
    BTNode<string> *root = dataNode;

    map<char, string> letter_morse;
};