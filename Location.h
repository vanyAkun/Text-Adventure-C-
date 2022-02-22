#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include "Item.h"

class Location
{
public:
    int number;
    string name;
    string description;
    vector<Item> items;
    vector<Location*> connections;

    void printText()
    {

        cout << endl;
        cout << "You are in the " << name << "." << description << endl;
        cout << endl;

    }
    void print()
    {
        cout << "Your current location is:  " << name << "." << endl;
        cout << "Items in this location: " << endl;
        for (Item i : items)
        {
            cout << i.getName() << " " << i.getDescription() << endl;
        }
    }

    Item* getItem(string itemName)
    {
        for (auto y = items.begin(); y != items.end(); y++)
        {
            if (y->getName() == itemName)
            {
                return &(*y);
            }
        }
        return nullptr;
    }

    bool take_item(Item* i)
    {
        for (auto y = items.begin(); y != items.end(); y++)
        {
            if (y->getName() == i->getName() && y->getDescription() == i->getDescription())
            {
                items.erase(y);
                return true;
            }
        }
        return false;
    };

    void drop_item(Item* i)
    {
        items.push_back(*i);
    };

    Location* getConnection(string& direction)
    {
        if (direction == "NORTH") // || direction == "north"
        {
            return connections[0];
        }
        else if (direction == "EAST")
        {
            return connections[1];
        }
        else if (direction == "WEST")
        {
            return connections[2];
        }
        else if (direction == "SOUTH")
        {
            return connections[3];
        }
        return nullptr;
    };


};
