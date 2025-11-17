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
#include "Item.h"		/* Item class       	*/
#include "Book.h"		/* Book class       	*/
#include "Movie.h"		/* Movie class      	*/
#include "Magazine.h"	/* Magazine class  		*/
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
	 * PRIVATE DATA MEMBER libraryInventory
	 * ---------------------------------------------------------------------
	 * Handles an inventory of Items. The number of columns, or
	 * compartments, is limited to 15. The number of rows is unrestricted.
	 * The limit of 15 columns will be handled in each function
	 * libraryInventory appears in.
	 **********************************************************************/
	vector<vector<Item*>> libraryInventory;


public:
	/***********************************************************************
	 * CONSTRUCTOR
	 * ---------------------------------------------------------------------
	 * Initializes an empty library inventory.
	 **********************************************************************/
	Library();

	/***********************************************************************
	 * DESTRUCTOR
	 * ---------------------------------------------------------------------
	 * Cleans up all dynamically allocated items in the inventory.
	 **********************************************************************/
	~Library();

	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION []
	 * ---------------------------------------------------------------------
	 * Overloads the C++ [] operator. In the Library class, it allows access
	 * to the private data member libraryInventory.
	 *
	 * EXAMPLE (without overloading)
	 * 		libraryInventory1.getInventory()[3][4];
	 *
	 * EXAMPLE (with overloading)
	 * 		libraryInventory1[3][4];
	 * ---------------------------------------------------------------------
	 * => Returns a reference to a vector of Item pointers.
	 **********************************************************************/
	vector<Item*>& operator[](const int& index);

	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION addItem
	 * ---------------------------------------------------------------------
	 * Adds an Item from the libraryInventory.
	 * ---------------------------------------------------------------------
	 * => Returns nothing; modifies libraryInventory.
	 **********************************************************************/
	void addItem(Item& item);
	
	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION checkoutItem
	 * ---------------------------------------------------------------------
	 * Checks out an Item from libraryInventory. Upon checkout, the system
	 * record the name of the person who checked out the item and the due
	 * due date for returning the item in a file.
	 * ---------------------------------------------------------------------
	 * => Returns nothing; gets user input and modifies a file.
	 **********************************************************************/
	void checkoutItem(ofstream& checkoutFile, Item& item, string name);
	
	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION checkinItem
	 * ---------------------------------------------------------------------
	 * Checks in an Item from libraryInventory. If the Item was never 
	 * checked out, the system will notify the user via console output.
	 * ---------------------------------------------------------------------
	 * => Returns nothing; outputs if 
	 **********************************************************************/
	void checkinItem(Item& item);
	
	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION printInventory
	 * ---------------------------------------------------------------------
	 * Prints out all Items and their shelf and compartment locations in 
	 * libraryInventory. 
	 * ---------------------------------------------------------------------
	 * => Returns nothing; outputs inventory.
	 **********************************************************************/
	void printInventory();
	
	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION printCheckOutedItems
	 * ---------------------------------------------------------------------
	 * Prints out all checked out Items and the name of the person who 
	 * checked them out and their due date.
	 * ---------------------------------------------------------------------
	 * => Returns nothing; outputs checked out inventory.
	 **********************************************************************/
	void printCheckOutedItems(ifstream& checkoutFile);
	
	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION swapItems
	 * ---------------------------------------------------------------------
	 * Swaps the contents of two compartments in libraryInventory. If one
	 * or both compartments are empty, the system will output an error.
	 * ---------------------------------------------------------------------
	 * => Returns nothing; outputs checked out inventory.
	 **********************************************************************/
	void swapItems(const int row1, const int col1, const int row2, const int col2);
	
};



#endif
