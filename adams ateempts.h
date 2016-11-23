#pragma once
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class MorseTree
{
private:
    map<char, string> letter_morse;

public:
    void fill_map();
    void create_MorseTree(ifstream& myfile);
    void encode(string letters);
    string decode(string morse_code);

};
