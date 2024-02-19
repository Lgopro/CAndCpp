/*
Rev: Liran Tzunam
Dev: Leonid Golovko
status: finished
date: 13/08/23
*/
#include <vector> /*vector use*/
#include <string> /*string use*/
#include <iostream> /*cout*/
#include "histo.hpp"

using namespace std;

const int EMPTY = 1;
const int BEGIN = 0;

void Histo()
{
    vector<string> emptyVector;
    string get_string;
    size_t counter = 1;
    while(EMPTY)
    {
        std::getline(std::cin, get_string);
        if(get_string == ".")
        {
            break;
        }
        emptyVector.push_back(get_string);
    }
    while(EMPTY != emptyVector.empty())
    {
        counter = 1;
        get_string = emptyVector[BEGIN];
        for(size_t i = 1; i < emptyVector.size(); ++i)
        {
            if(get_string == emptyVector[i])
            {
                emptyVector.erase(emptyVector.begin() + i);
                ++counter;
            }
        }
        if(EMPTY != emptyVector.empty())
        {
            emptyVector.erase(emptyVector.begin());
        }
        if(EMPTY != counter)
        {
            cout << "x " << counter << " " << get_string << endl;
        }
        else
        {
            cout << get_string << endl;
        }
    }
}

