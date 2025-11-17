#include "Library.h"
#include <fstream>

Library::Library()
{
    libraryInventory = vector<vector<Item*>>();
}

Library::~Library()
{
    for (int i = 0; i < libraryInventory.size(); i++)
    {
        for (int j = 0; j < libraryInventory[i].size(); j++)
        {
            delete libraryInventory[i][j];
        }
    }
}

vector<Item*>& Library::operator[](const int& index)
{
    return libraryInventory[index];
}

void Library::addItem(Item& item)
{
    libraryInventory.push_back(vector<Item*>());
    libraryInventory.back().push_back(&item);
}

void Library::checkoutItem(ofstream& checkoutFile, Item& item, string name)
{
    string dueDate = "12/31/2025";
    item.checkout(name, dueDate);
    checkoutFile << item.getName() << endl << name << endl << dueDate << endl;
}

void Library::checkinItem(Item& item)
{
    item.checkin();
}

void Library::printInventory()
{
    for (int i = 0; i < libraryInventory.size(); i++)
    {
        for (int j = 0; j < libraryInventory[i].size(); j++)
        {
            libraryInventory[i][j]->print(cout);
        }
    }
}

void Library::printCheckOutedItems(ifstream& checkoutFile)
{
    string itemName, borrowerName, dueDate;
    while (getline(checkoutFile, itemName) && getline(checkoutFile, borrowerName) && getline(checkoutFile, dueDate))
    {
        cout << "Item: " << itemName << " | Borrower: " << borrowerName << " | Due Date: " << dueDate << endl;
    }
}

void Library::swapItems(const int row1, const int col1, const int row2, const int col2)
{
    Item* temp = libraryInventory[row1][col1];
    libraryInventory[row1][col1] = libraryInventory[row2][col2];
    libraryInventory[row2][col2] = temp;
}