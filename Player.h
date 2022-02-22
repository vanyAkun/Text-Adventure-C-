#pragma once

#include "Location.h"
#include "Item.h"
#include <vector>
using namespace std;

class Player
{

public:
    Location* location;
    vector<Item> inventory;

    bool inventoryContainsItem(vector<Item> inventory, Item* i)
    {
        for (int x = 0; x < inventory.size(); x++)
        {
            if (inventory[x].getName() == i->getName())
                return true;
        }
        return false;
    }

    bool hasItem(Item* i)
    {
        return inventoryContainsItem(this->inventory, i);
    };

    bool takeItem(Item* i)
    {
        if (inventoryContainsItem(location->items, i))
        {
            inventory.push_back(*i);
            return location->take_item(i);
        }
        return false;
    };

    bool dropItem(Item* i)
    {
        if (hasItem(i))
        {
            for (auto y = inventory.begin(); y != inventory.end(); y++)
            {
                if (y->getName() == i->getName())
                {
                    location->drop_item(&(*y));
                    inventory.erase(y);
                    return true;
                }
            }
        }
        return false;
    };

    void printStatus()
    {
        cout << "The current locations is: " << location->name << endl;
        cout << "You have the following items: " << endl;
        for (Item i : inventory)
        {
            cout << i.getName() << endl;
            cout << i.getDescription() << endl;
        }
    }


};