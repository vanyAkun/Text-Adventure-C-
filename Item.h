#pragma once
using namespace std;
#include <string>
class Item
{
public:
    string name;
    string description;

    string getName()
    {
        return this->name;
    }
    string getDescription()
    {
        return this->description;
    }
};

