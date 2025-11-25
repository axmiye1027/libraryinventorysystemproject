#include "Library.h"
#include <fstream>

Library::Library()
{
    shelves = vector<Shelf>();
}

Library::Library(int numberOfShelves)
{
	if(numberOfShelves < 0)
	{
		throw invalid_argument("Cannot initialize amount of shelves to a negative number");
	}

	shelves = vector<Shelf>(numberOfShelves);
}

Library::~Library()
{
    // Delete all items from compartments
    for (int i = 0; i < (int)shelves.size(); i++)
    {
        for (int j = 0; j < Shelf::getMaxCompartments(); j++)
        {
            Item* item = shelves[i][j].getItem();
            if (item != nullptr)
            {
                delete item;
                shelves[i][j].setItem(nullptr);
            }
        }
    }
}

void Library::addShelf()
{
	shelves.push_back(Shelf());
}

void Library::validateRow(int row) const
{
	if(row < 0 || row >= (int) shelves.size())
	{
		throw out_of_range("Invalid row index");
	}
}

void Library::validateColumn(int row, int col) const
{
	validateRow(row);

	if(col < 0 || col >= Shelf::getMaxCompartments())
	{
		throw out_of_range("Invalid column index");
	}

	if(shelves[row][col].isEmpty())
	{
		throw runtime_error("No item in this compartment");
	}
}

Shelf& Library::operator[](int index)
{
	validateRow(index);
    return shelves[index];
}

void Library::addItem(Item* item, int row, int col)
{
	if(item == nullptr)
	{
		throw invalid_argument("Cannot add empty Item");
	}

    validateRow(row);

    if(col < 0 || col >= Shelf::getMaxCompartments())
    {
    	throw out_of_range("Invalid column index");
    }

    if(!shelves[row][col].isEmpty())
    {
    	throw runtime_error("Item already exists in this compartment");
    }

    shelves[row][col].setItem(item);
}

void Library::checkoutItem(ofstream& checkoutFile, int row, int col, const string name)
{
	if(!checkoutFile)
	{
		throw runtime_error("File not opened");
	}

	if(name.empty())
	{
		throw invalid_argument("Name cannot be blank");
	}

	validateColumn(row, col);
	
	Compartment& compartment = shelves[row][col];
	
	if(compartment.getIsCheckedOut())
	{
		throw runtime_error("Item is already checked out");
	}

    string dueDate = "12/31/2025";

    if(!compartment.checkout(name, dueDate))
    {
    	throw runtime_error("Cannot check out item");
    }

    Item* item = compartment.getItem();
    if(item != nullptr)
    {
    	checkoutFile << item->getName() << endl << name << endl << dueDate << endl;
    }
}

void Library::checkinItem(int row, int col)
{
	validateColumn(row, col);
	
	Compartment& compartment = shelves[row][col];
	
    if(!compartment.checkin())
    {
    	throw runtime_error("Item has not been checked out");
    }
}

void Library::printInventory() const
{
    for (int i = 0; i < (int)shelves.size(); i++)
    {
        for (int j = 0; j < Shelf::getMaxCompartments(); j++)
        {
            const Compartment& compartment = shelves[i][j];
            Item* item = compartment.getItem();

            if(item != nullptr && !compartment.getIsCheckedOut())
            {
            	item->print(cout);
            	cout << " - Shelf: " << i << ", Compartment: " << j << endl;
            }
        }
    }
}

void Library::printCheckedOutItems() const
{
    bool foundCheckedOut = false;
    
    for (int i = 0; i < (int)shelves.size(); i++)
    {
        for (int j = 0; j < Shelf::getMaxCompartments(); j++)
        {
            const Compartment& compartment = shelves[i][j];
            
            if(compartment.getIsCheckedOut() && !compartment.isEmpty())
            {
                Item* item = compartment.getItem();
                if(item != nullptr)
                {
                    cout << "Item: " << item->getName() 
                         << " | Borrower: " << compartment.getBorrowerName()
                         << " | Due Date: " << compartment.getDueDate() << endl;
                    foundCheckedOut = true;
                }
            }
        }
    }
    
    if(!foundCheckedOut)
    {
        cout << "No items currently checked out." << endl;
    }
}

void Library::swapItems(int row1, int col1, int row2, int col2)
{
	validateColumn(row1, col1);
	validateColumn(row2, col2);

	Compartment& comp1 = shelves[row1][col1];
	Compartment& comp2 = shelves[row2][col2];

	// Save state from both compartments
	Item* item1 = comp1.getItem();
	Item* item2 = comp2.getItem();
	bool checkedOut1 = comp1.getIsCheckedOut();
	bool checkedOut2 = comp2.getIsCheckedOut();
	string borrower1 = comp1.getBorrowerName();
	string borrower2 = comp2.getBorrowerName();
	string dueDate1 = comp1.getDueDate();
	string dueDate2 = comp2.getDueDate();
	
	// Clear both compartments
	if(checkedOut1) comp1.checkin();
	if(checkedOut2) comp2.checkin();
	
	// Swap items
	comp1.setItem(item2);
	comp2.setItem(item1);
	
	// Restore checkout states
	if(checkedOut2 && item2 != nullptr)
	{
		comp1.checkout(borrower2, dueDate2);
	}
	if(checkedOut1 && item1 != nullptr)
	{
		comp2.checkout(borrower1, dueDate1);
	}
}
