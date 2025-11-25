#include "Library.h"
#include <iostream>
#include <stdexcept>
#include <fstream>

Library::Library()
{
	shelves = vector<Shelf>();
}

Library::Library(int numOfShelves)
{
	if(numOfShelves < 0)
	{
		throw invalid_argument("Cannot initialize number of shelves to a negative number.\n");
	}

	shelves = vector<Shelf>(numOfShelves);
}

Library::~Library(){}

Shelf& Library::operator[](int index)
{
	validateShelf(index);
	return shelves[index];
}

bool Library::addItem(Item* item, int shelf, int compartment)
{
	if(item == nullptr)
	{
		throw invalid_argument("Cannot add an empty Item\n");
	}

	validateCompartment(shelf, compartment);

	if(shelves[shelf][compartment] == nullptr)
	{
		shelves[shelf][compartment] = item;
		return true;
	}

	return false;
}

bool Library::checkOutItem(CheckOutInfo* info, int shelf, int compartment)
{
	validateCompartment(shelf, compartment);

	if(info == nullptr)
	{
		throw invalid_argument("Checkout information must be provided\n");
	}

	//Validates non empty string for borrow's name and due date
	if(info->name.empty() || info->dueDate.empty())
	{
		throw invalid_argument("Name nor due date cannot be empty\n");
	}

	//Validates that item is not empty and that checkOutInfo is empty
	if(shelves[shelf][compartment] != nullptr &&
		shelves[shelf].getCheckOutInfo(compartment) == nullptr)
	{
		shelves[shelf].getCheckOutInfo(compartment) = info;
		return true;
	}

	return false;
}

bool Library::checkInItem(int id, int shelf, int compartment)
{
	validateCompartment(shelf, compartment);

	//Validates id matches item checked out at that compartment's location
	//Also validates that the compartment is not pointing to an empty checkout
	if(shelves[shelf][compartment]->getID() == id &&
	   shelves[shelf].getCheckOutInfo(compartment) != nullptr)
	{
		shelves[shelf].getCheckOutInfo(compartment) = nullptr;
		return true;
	}

	return false;
}

void Library::printItemsInStorage(ostream& out)
{
	for(int i = 0; i < (int)shelves.size(); i++)
	{
		for(int j = 0; j < MAX_COMPARTMENTS; j++)
		{
			//Prints the compartments with empty checkout informations
			if(shelves[i][j] != nullptr && shelves[i].getCheckOutInfo(j) == nullptr)
			{
				out << "Shelf: " << i << "  Compartment: " << j;
				out << shelves[i][j];
				out << endl;
			}
		}
	}
}

void Library::printCheckOutItems(ostream& out)
{
	for(int i = 0; i < (int)shelves.size(); i++)
	{
		for(int j = 0; j < MAX_COMPARTMENTS; j++)
		{
			//Prints the compartments with full checkout informations
			if(shelves[i][j] != nullptr && shelves[i].getCheckOutInfo(j) != nullptr)
			{
				out << "Checked out by: " << shelves[i].getCheckOutInfo(j)->name;
				out << endl;
				out << "Date due: " << shelves[i].getCheckOutInfo(j)->dueDate;
				out << shelves[i][j];
				out << endl;
			}
		}
	}
}

bool Library::swapItems(int shelf1, int comp1, int shelf2, int comp2)
{
	validateCompartment(shelf1, comp1);
	validateCompartment(shelf2, comp2);

	//Validates that items at those compartments are not empty and not checked out
	if(shelves[shelf1][comp1] != nullptr && shelves[shelf2][comp2] != nullptr &&
		shelves[shelf1].getCheckOutInfo(comp1) == nullptr && shelves[shelf2].getCheckOutInfo(comp2) == nullptr)
	{
		Item* temp = shelves[shelf1][comp1];
		shelves[shelf1][comp1] = shelves[shelf2][comp2];
		shelves[shelf2][comp2] = temp;
		return true;
	}

	return false;
}

void Library::addShelves(int numOfShelves)
{
	if(numOfShelves < 0)
	{
		throw invalid_argument("Cannot add a negative number of shelves\n");
	}

	for(int i = 0; i < numOfShelves; i++)
	{
		shelves.push_back(Shelf());
	}
}

void Library::validateShelf(int shelf)
{
	if(shelf < 0 || shelf >= (int)shelves.size())
	{
		throw out_of_range("Invalid shelf index\n");
	}
}

void Library::validateCompartment(int shelf, int comp)
{
	validateShelf(shelf);

	if(comp < 0 || comp >= MAX_COMPARTMENTS)
	{
		throw invalid_argument("Invalid compartment index\n");
	}
}
