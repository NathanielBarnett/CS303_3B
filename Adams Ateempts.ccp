#include "MorseTree.h"

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

void MorseTree::create_MorseTree(ifstream& myfile)
{
    //Create a vector to hold each line of code from the file.
    vector<string> sorted_morse;
    myfile.open("morse.txt");
    string line;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            sorted_morse.push_back(line);
        }
        myfile.close();
    }
    //Sort the string of vectors based on the length of each string.
    for (int fill = 0; fill < sorted_morse.size(); ++fill)
    {
        int min = sorted_morse[fill].length();
        for (int next = fill + 1; next < sorted_morse.size(); ++next)
        {
            if (sorted_morse[next] < sorted_morse[min])
                min = next;
        }
        if (sorted_morse[fill] != sorted_morse[min])
        {
            string temp = sorted_morse[min];
            sorted_morse[min] = sorted_morse[fill];
            sorted_morse[fill] = temp;
        }
    }
    //Create a Binary Search Tree based off the sorted vector.
}

void MorseTree::encode(string letters)
{
    while (letters.length() != 0)
    {
        cout << letter_morse.find(letters[0])->second << " ";
        letters.erase(letters[0]);
    }
}

string MorseTree::decode(string morse_code)
{

}
