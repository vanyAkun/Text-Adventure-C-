#pragma once
using namespace std;

void Intro()
{
    cout << endl;
    cout << "You woke up in the middle of the night remembering that your Programming Coursework is due tomorrow." << endl;
    cout << "You better get to your PC and finish your job!You should also feed your cat though..." << endl;
    cout << endl;
}

void OptionGiven()
{
    cout << endl;
    cout << endl;
    cout << "What would you do? (Type HELP for instructions)" << endl;
    cout << endl;
    cout << endl;
}

void Help()
{

    cout << endl;
    cout << "Type : MOVE NORTH/SOUTH/EAST or WEST to move into a direction" << endl;
    cout << "Type : LOOK to get the current location and list of items" << endl;
    cout << "Type : TAKE ITEMNAME to pick up an item" << endl;
    cout << "Type : DROP ITEMNAME to drop an item" << endl;
    cout << "Type : QUIT to quit the game" << endl;
    cout << endl;

}

