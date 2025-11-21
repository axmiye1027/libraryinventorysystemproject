/***************************************************************************
 * AUTHOR			: Amy X, Ryland L, Cristal D, Elizabeth S, Paul S.
 * PROJECT #2		: Library Inventory System
 * CLASS			: CS 1C
 * SECTION			: TTh 8a
 * DUE DATE			: ...
 **************************************************************************/

#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>		/* cin, cout			*/
#include <iomanip>		/* setw					*/
#include <string>		/* string class			*/
#include <vector>		/* vector STL	 		*/
#include <sstream>		/* ostringstream 		*/
#include <fstream>		/* ofstream				*/
#include <stdexcept>    /* exceptions			*/
#include "Item.h"		/* Item class       	*/
#include "Book.h"		/* Book class       	*/
#include "Movie.h"		/* Movie class      	*/
#include "Magazine.h"	/* Magazine class  		*/
#include "Shelf.h"		/* Shelf class			*/
using namespace std;

/***************************************************************************
 * CLASS Library
 * -------------------------------------------------------------------------
 * Represents a single library system of Items.
 **************************************************************************/
class Library
{
private:
	/***********************************************************************
	 * PRIVATE DATA MEMBER shelves
	 * ---------------------------------------------------------------------
	 * Vector of Shelf objects. Each shelf contains 15 compartments.
	 * The number of shelves is unrestricted.
	 **********************************************************************/
	vector<Shelf> shelves;

public:
	/***********************************************************************
	 * CONSTRUCTOR
	 * ---------------------------------------------------------------------
	 * Initializes an empty library inventory.
	 **********************************************************************/
	Library();

	/***********************************************************************
	 * CONSTRUCTOR
	 * ---------------------------------------------------------------------
	 * Initializes a library inventory with a number of shelves
	 **********************************************************************/
	Library(int numberOfShelves);

	/***********************************************************************
	 * DESTRUCTOR
	 * ---------------------------------------------------------------------
	 * Cleans up all dynamically allocated items in the inventory.
	 **********************************************************************/
	~Library();

	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION addShelf
	 * ---------------------------------------------------------------------
	 * Adds another row(shelf) to the library inventory
	 * ---------------------------------------------------------------------
	 * => Returns nothing; modifies libraryInventory size
	 **********************************************************************/
	void addShelf();

	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION []
	 * ---------------------------------------------------------------------
	 * Overloads the C++ [] operator. In the Library class, it allows access
	 * to shelves. Returns a Shelf reference which can then be indexed
	 * again to access compartments.
	 *
	 * EXAMPLE (without overloading)
	 * 		library1.getShelf(3).getCompartment(4);
	 *
	 * EXAMPLE (with overloading)
	 * 		library1[3][4];  // Returns Compartment&
	 * ---------------------------------------------------------------------
	 * => Returns a reference to a Shelf.
	 **********************************************************************/
	Shelf& operator[](int index);

	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION addItem
	 * ---------------------------------------------------------------------
	 * Adds an Item from the libraryInventory.
	 * ---------------------------------------------------------------------
	 * => Returns nothing; modifies libraryInventory.
	 **********************************************************************/
	void addItem(Item* item, int row, int col);

	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION checkoutItem
	 * ---------------------------------------------------------------------
	 * Checks out an Item from libraryInventory. Upon checkout, the system
	 * record the name of the person who checked out the item and the due
	 * due date for returning the item in a file.
	 * ---------------------------------------------------------------------
	 * => Returns nothing; gets user input and modifies a file.
	 **********************************************************************/
	void checkoutItem(ofstream& checkoutFile, int row, int col, const string name);

	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION checkinItem
	 * ---------------------------------------------------------------------
	 * Checks in an Item from libraryInventory at the specified location.
	 * If the Item was never checked out, the system will throw an exception.
	 * ---------------------------------------------------------------------
	 * => Returns nothing; checks in item at compartment
	 **********************************************************************/
	void checkinItem(int row, int col);

	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION printInventory
	 * ---------------------------------------------------------------------
	 * Prints out all Items and their shelf and compartment locations in
	 * libraryInventory.
	 * ---------------------------------------------------------------------
	 * => Returns nothing; outputs inventory.
	 **********************************************************************/
	void printInventory() const;

	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION printCheckOutedItems
	 * ---------------------------------------------------------------------
	 * Prints out all checked out Items and the name of the person who
	 * checked them out and their due date. Reads from actual compartment
	 * states to show current checked-out status.
	 * ---------------------------------------------------------------------
	 * => Returns nothing; outputs checked out inventory.
	 **********************************************************************/
	void printCheckedOutItems() const;

	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION swapItems
	 * ---------------------------------------------------------------------
	 * Swaps the contents of two compartments in libraryInventory. If one
	 * or both compartments are empty, the system will output an error.
	 * ---------------------------------------------------------------------
	 * => Returns nothing; outputs checked out inventory.
	 **********************************************************************/
	void swapItems(int row1, int col1, int row2, int col2);

	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION validateRow
	 * ---------------------------------------------------------------------
	 * Validates row index for in bounds, throws exception if invalid
	 * ---------------------------------------------------------------------
	 * => Returns nothing; validates row
	 **********************************************************************/
	void validateRow(int row) const;

	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION validateColumn
	 * ---------------------------------------------------------------------
	 * Validates column index for in bounds and checks if compartment has item
	 * ---------------------------------------------------------------------
	 * => Returns nothing; validates column in a row
	 **********************************************************************/
	void validateColumn(int row, int col) const;

};



#endif
