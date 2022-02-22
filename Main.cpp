#include <iostream>
#include "Item.h"
#include "Location.h"
#include "Player.h"
#include "Functions.h"
using namespace std;


int main(int argc, char const* argv[])
{

    string command, input;

    Location LivingRoom;
    Location Kitchen;
    Location Bathroom;
    Location Studio;
    Location Bedroom;

    Item PEN;
    Item GLASS;
    Item FOOD;
    Item PASSWORD;
    Item KEY;

    vector<Item> LivingRoomItems;
    vector<Item> BathroomItems;
    vector<Item> KitchenItems;
    vector<Item> BedroomItems;

    PEN.name = "PEN";
    PEN.description = "A blue pen, it doesn't seem to work.";

    GLASS.name = "GLASS";
    GLASS.description = "It's from the bathroom sink...I would not drink it.";

    FOOD.name = "FOOD";
    FOOD.description = "My cat's favourite food.";

    PASSWORD.name = "PASSWORD";
    PASSWORD.description = "Why did I write my PC password on a napkin...";

    KEY.name = "KEY";
    KEY.description = "Ah!My Studio Key!";

    LivingRoomItems.push_back(PEN);
    LivingRoom.number = 1;
    LivingRoom.name = "Living Room";
    LivingRoom.description = "The living room is a bit messy. You should clean it.";
    LivingRoom.items = LivingRoomItems;

    BathroomItems.push_back(GLASS);
    Bathroom.number = 2;
    Bathroom.name = "Bathroom";
    Bathroom.description = "It's a small bathroom, but there is a concerning amount of rubber ducks...";
    Bathroom.items = BathroomItems;

    KitchenItems.push_back(FOOD);
    KitchenItems.push_back(PASSWORD);
    Kitchen.name = "Kitchen";
    Kitchen.description = "It's a red kitchen. It seems that the fridge needs to be restocked.";
    Kitchen.number = 3;
    Kitchen.items = KitchenItems;

    BedroomItems.push_back(KEY);
    Bedroom.number = 4;
    Bedroom.name = "Bedroom";
    Bedroom.description = "Cozy bedroom. Clean sheets are the best feeling ever!";
    Bedroom.items = BedroomItems;

    Studio.name = "Studio";
    Studio.description = "There's a PC, a gaming chair and a lamp...You could decorate it better...";
    Studio.number = 5;
    Studio.items = vector<Item>();

    LivingRoom.connections.push_back(&Bathroom);
    LivingRoom.connections.push_back(&Kitchen);
    LivingRoom.connections.push_back(&Studio);
    LivingRoom.connections.push_back(&Bedroom);

    Bedroom.connections.push_back(&LivingRoom);
    Bedroom.connections.push_back(nullptr);
    Bedroom.connections.push_back(nullptr);
    Bedroom.connections.push_back(nullptr);

    Kitchen.connections.push_back(nullptr);
    Kitchen.connections.push_back(nullptr);
    Kitchen.connections.push_back(&LivingRoom);
    Kitchen.connections.push_back(nullptr);

    Bathroom.connections.push_back(nullptr);
    Bathroom.connections.push_back(nullptr);
    Bathroom.connections.push_back(nullptr);
    Bathroom.connections.push_back(&LivingRoom);

    Studio.connections.push_back(nullptr);
    Studio.connections.push_back(&LivingRoom);
    Studio.connections.push_back(nullptr);
    Studio.connections.push_back(nullptr);

    Player player;
    player.inventory = vector<Item>();
    player.location = &LivingRoom;

    Intro();

    while (true)
    {

        OptionGiven();
        cout << ">>";
        cin >> command;

        if (command == "MOVE")
        {
            cin >> input;

            if (player.location->getConnection(input) != nullptr && player.location->getConnection(input)->name == "Studio")
            {

                if (player.hasItem(&KEY))
                {
                    player.location = player.location->getConnection(input);
                    if (player.hasItem(&PASSWORD))
                    {
                        cout << "You check you password and log in into your PC, ready for a night playing games. Have fun!" << endl;
                        cout << endl;
                        cout << "Wait..." << endl;
                        cout << endl;
                        cout << "What about your coursework?????" << endl;
                        return 0;
                    }
                }
                else
                {
                    cout << "I need the KEY to unlock my Studio. Was it on my night stand??" << endl;
                }
            }
            else
            {
                if (input == "NORTH" || input == "EAST" || input == "SOUTH" || input == "WEST")
                {
                    if (player.location->getConnection(input) != nullptr)

                    {

                        player.location = player.location->getConnection(input);
                        player.location->printText();

                    }
                }
                else
                    cout << "Not valid. Try again." << endl;
                continue;
            }
        }
        else if (command == "LOOK")
        {
            player.location->print();
        }
        else if (command == "TAKE")
        {
            cin >> input;
            Item* newI;
            newI = player.location->getItem(input);
            if (newI != nullptr)
            {
                player.takeItem(newI);
                cout << "You picked the item. " << newI->getName() << endl;
                continue;
            }

            cout << "That item is not here. " << endl;
        }
        else if (command == "DROP")
        {
            cin >> input;
            Item newItem;
            newItem.name = input;
            if (player.dropItem(&newItem))
            {
                cout << "You dropped: " << newItem.getName() << endl;
                continue;
            }
            cout << "You don't have that item. " << endl;
        }
        else if (command == "QUIT")
        {
            cout << " See you soon." << endl;
            exit(1);
        }
        else if (command == "HELP")
        {
            Help();
            continue;
        }

        else
        {
            cout << " I don't understand this input." << endl;
        }
    }

    return 0;
}
