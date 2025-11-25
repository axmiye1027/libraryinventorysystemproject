/***************************************************************************
 * AUTHOR			: Amy X, Ryland L, Cristal D, Elizabeth S, Paul S.
 * PROJECT #2		: Library Inventory System
 * CLASS			: CS 1C
 * SECTION			: TTh 8a
 * DUE DATE			: Nov 25, 2025
 **************************************************************************/

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include "Shelf.h"

/***************************************************************************
 * CLASS Library
 * -------------------------------------------------------------------------
 * Represents a single library system of Items.
 **************************************************************************/
class Library
{
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
		Library(int numOfShelves);

		//Destructor
		~Library();

		/***********************************************************************
		 * PUBLIC MEMBER FUNCTION []
		 * ---------------------------------------------------------------------
		 * Overloads the C++ [] operator. In the Library class, it allows access
		 * to shelves. Returns a Shelf reference which can then be indexed
		 * again to access item in a compartment.
		 *
		 * EXAMPLE (without overloading)
		 * 		library1.getShelf(3).getCompartment(4);
		 *
		 * EXAMPLE (with overloading)
		 * 		library1[3][4];  // Returns Item*&
		 * ---------------------------------------------------------------------
		 * => Returns a reference to a Shelf.
		 **********************************************************************/
		Shelf& operator[](int index);

		/***********************************************************************
		 * PUBLIC MEMBER FUNCTION addItem
		 * ---------------------------------------------------------------------
		 * Adds an Item to the library at a specific shelf and index if both
		 * indexes are valid and item not already occupying compartment
		 * ---------------------------------------------------------------------
		 * => Returns boolean true if Item was successfully added
		 **********************************************************************/
		bool addItem(Item* item, int shelf, int compartment);


		/***********************************************************************
		 * PUBLIC MEMBER FUNCTION checkOutItem
		 * ---------------------------------------------------------------------
		 * Receives the check out information of the borrower, and the shelf and
		 * index of the item to borrow.
		 * Will then check if information is provided and if item not empty
		 * nor checked out.
		 * Will then have the compartment hold the borrower information till 
		 * checked in.
		 * ---------------------------------------------------------------------
		 * => Returns boolean true if item is successfully checked out
		 **********************************************************************/
		bool checkOutItem(CheckOutInfo* info, int shelf, int compartment);

		/***********************************************************************
		 * PUBLIC MEMBER FUNCTION checkInItem
		 * ---------------------------------------------------------------------
		 * Receives the ID number of the item attempting to be checked in as well
		 * as the shelf and compartment index that the item was located.
		 * If all are correct, checks in item by setting compartment's check out
		 * info to a nullptr
		 * ---------------------------------------------------------------------
		 * => Returns a boolean true if the Item was successfully checked out
		 **********************************************************************/
		bool checkInItem(int id, int shelf, int compartment);

		/***********************************************************************
		 * PUBLIC MEMBER FUNCTION printItemsInStorage
		 * ---------------------------------------------------------------------
		 * Receives an output stream variable and outputs all items in 
		 * storage(not checked out) and their information to console or to file
		 * ---------------------------------------------------------------------
		 * => Returns nothing; outputs inventory.
		 **********************************************************************/
		void printItemsInStorage(ostream& out);

		/***********************************************************************
		 * PUBLIC MEMBER FUNCTION printCheckOutItems
		 * ---------------------------------------------------------------------
		 * Receives an output stream variable and output the information of all
		 * items in storage and the information of the item's borrower - 
		 * their name and the item's due date.
		 * ---------------------------------------------------------------------
		 * => Returns nothing; outputs checked out inventory.
		 **********************************************************************/
		void printCheckOutItems(ostream& out);

		/***********************************************************************
		 * PUBLIC MEMBER FUNCTION swapItems
		 * ---------------------------------------------------------------------
		 * Receives the location of two items and checks if the item's aren't
		 * checked out or empty. Performs a swap.
		 * ---------------------------------------------------------------------
		 * => Returns a boolean true if the items were successfully swapped
		 **********************************************************************/
		bool swapItems(int shelf1, int compartment1, int shelf2, int compartment2);
		
		/***********************************************************************
		 * PUBLIC MEMBER FUNCTION addShelves
		 * ---------------------------------------------------------------------
		 * Adds another amount of shelves to library 
		 * ---------------------------------------------------------------------
		 * => Returns nothing; modifies libraryInventory size
		 **********************************************************************/
		void addShelves(int numOfShelves);

	private:
		/***********************************************************************
		 * PRIVATE DATA MEMBER shelves
		 * ---------------------------------------------------------------------
		 * Vector of Shelf objects. Each shelf contains 15 compartments.
		 * The number of shelves is unrestricted.
		 **********************************************************************/
		vector<Shelf> shelves;

		/***********************************************************************
		 * PRIVATE MEMBER FUNCTION validateShelf
		 * ---------------------------------------------------------------------
		 * Validates shelf index, if in bounds in existing amount of shelves
		 * ---------------------------------------------------------------------
		 * => Returns nothing; throws exception if invalid
		 **********************************************************************/
		void validateShelf(int shelf);

		/***********************************************************************
		 * PRIVATE MEMBER FUNCTION validateCompartment
		 * ---------------------------------------------------------------------
		 * Validate the shelf and compartment index. Checks if shelf is valid
		 * first then validate that compartment index is not a negative value
		 * nor a value greater that the max amount of compartments per shelf.
		 * ---------------------------------------------------------------------
		 * => Returns nothing; throws exception if invalid
		 **********************************************************************/
		void validateCompartment(int shelf, int comp);
};



#endif /* LIBRARY_H_ */
