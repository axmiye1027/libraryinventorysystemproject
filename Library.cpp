#include "Library.h"
#include <fstream>

Library::Library()
{
    libraryInventory = vector<vector<Item*>>();
}

Library::Library(int numberOfShelves)
{
	if(numberOfShelves < 0)
	{
		throw invalid_argument("Cannot initialize amount of shelves to a negative number");
	}

	libraryInventory = vector<vector<Item*>>(numberOfShelves, vector<Item*>(MAX_COMPARTMENTS, nullptr));
}

Library::~Library()
{
    for (int i = 0; i < (int)libraryInventory.size(); i++)
    {
        for (int j = 0; j < (int)libraryInventory[i].size(); j++)
        {
            delete libraryInventory[i][j];
        }
    }
}

void Library::addShelf()
{
	libraryInventory.push_back(vector<Item*>(MAX_COMPARTMENTS, nullptr));
}

void Library::validateRow(int row) const
{
	if(row < 0 || row >= (int) libraryInventory.size())
	{
		throw out_of_range("Invalid row index");
	}
}

void Library::validateColumn(int row, int col) const
{
	validateRow(row);

	if(col < 0 || col >= MAX_COMPARTMENTS)
	{
		throw out_of_range("Invalid column index");
	}

	if(col >= (int) libraryInventory[row].size() || libraryInventory[row][col] == nullptr)
	{
		throw runtime_error("No item in this compartment");
	}


}

vector<Item*>& Library::operator[](int index)
{
	validateRow(index);
    return libraryInventory[index];
}

void Library::addItem(Item* item, int row, int col)
{
	if(item == nullptr)
	{
		throw invalid_argument("Cannot add empty Item");
	}

    validateRow(row);

    if(col < 0 || col >= MAX_COMPARTMENTS)
    {
    	throw out_of_range("Invalid column index");
    }

    if(libraryInventory[row][col] != nullptr)
    {
    	throw runtime_error("Item already exists in this compartment");
    }

    libraryInventory[row][col] = item;
}

void Library::checkoutItem(ofstream& checkoutFile, Item& item, const string name)
{
	if(!checkoutFile)
	{
		throw runtime_error("File not opened");
	}

	if(name.empty())
	{
		throw invalid_argument("Name cannot be blank");
	}

    string dueDate = "12/31/2025";

    if(!item.checkout(name, dueDate))
    {
    	throw runtime_error("Item is already checked out");
    }

    checkoutFile << item.getName() << endl << name << endl << dueDate << endl;
}

void Library::checkinItem(Item& item)
{
    if(!item.checkin())
    {
    	throw runtime_error("Item has not been checked out");
    }
}

void Library::printInventory() const
{
    for (int i = 0; i < (int)libraryInventory.size(); i++)
    {
        for (int j = 0; j < MAX_COMPARTMENTS; j++)
        {
            Item* item = libraryInventory[i][j];

            if(item != nullptr && !item -> isCheckedOut())
            {
            	item->print(cout);
            	cout << endl;
            }
        }
    }
}

void Library::printCheckOutedItems(ifstream& checkoutFile) const
{
	if(!checkoutFile)
	{
		throw runtime_error("File not opened");
	}

    string itemName, borrowerName, dueDate;

    while (getline(checkoutFile, itemName) &&
    	   getline(checkoutFile, borrowerName) &&
		   getline(checkoutFile, dueDate))
    {
        cout << "Item: " << itemName << " | Borrower: " << borrowerName << " | Due Date: " << dueDate << endl;
    }
}

void Library::swapItems(int row1, int col1, int row2, int col2)
{
	validateColumn(row1, col1);
	validateColumn(row2, col2);

    Item* temp = libraryInventory[row1][col1];
    libraryInventory[row1][col1] = libraryInventory[row2][col2];
    libraryInventory[row2][col2] = temp;
}
