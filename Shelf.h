/***************************************************************************
 * AUTHOR			: Amy X, Ryland L, Cristal D, Elizabeth S, Paul S.
 * PROJECT #2		: Library Inventory System
 * CLASS			: CS 1C
 * SECTION			: TTh 8a
 * DUE DATE			: ...
 **************************************************************************/

 #ifndef SHELF_H_
#define SHELF_H_

#include "Item.h"
#include "Book.h"
#include "Magazine.h"
#include "Movie.h"

/***************************************************************************
 * STRUCT CheckOutInfo
 * -------------------------------------------------------------------------
 * Represents the check out information of borrower and the due date
 **************************************************************************/
struct CheckOutInfo
{
	string name = "";
	string dueDate = "";

	CheckOutInfo(string n, string due)
	{
		name = n;
		dueDate = due;
	}
};

/***************************************************************************
 * STRUCT Compartment
 * -------------------------------------------------------------------------
 * Represents a compartment in a library. Holds a pointer to an Item
 * and holds a pointer to it's check out information.
 **************************************************************************/
struct Compartment
{
	//Set both pointer to null - empty item and non-checkedOut
	Item* item = nullptr;
	CheckOutInfo* checkoutInfo = nullptr;
};

//CONSTANT VARIABLE - max amount of compartments per shelf 
const int MAX_COMPARTMENTS = 15;

/***************************************************************************
 * CLASS Shelf
 * -------------------------------------------------------------------------
 * Represents a single shelf containing 15 compartments.
 **************************************************************************/
class Shelf
{
	public:
		/***********************************************************************
		 * CONSTRUCTOR
		 * ---------------------------------------------------------------------
		 * Initializes an empty shelf with 15 empty compartments.
		 **********************************************************************/
		Shelf();

		/***********************************************************************
		 * DESTRUCTOR
		 * ---------------------------------------------------------------------
		 * Deallocates memory for pointers to Item and checkOutInfo
		 **********************************************************************/
		~Shelf();

		/***********************************************************************
		 * PUBLIC MEMBER FUNCTION []
		 * ---------------------------------------------------------------------
		 * Overloads the [] operator to access items in that compartment
		 * Throws exception if index is out of bounds.
		 * ---------------------------------------------------------------------
		 * => Returns a pointer reference to the Item located at that index
		 **********************************************************************/
		Item*& operator[](int index);

		/***********************************************************************
		 * PUBLIC MEMBER FUNCTION getCheckOutInfo
		 * ---------------------------------------------------------------------
		 * Accesses the checkOutInfo of that compartment at that index
		 * Throws exception if index is out of bounds.
		 * ---------------------------------------------------------------------
		 * => Returns pointer reference to the compartment's check out info
		 **********************************************************************/
		CheckOutInfo*& getCheckOutInfo(int index);

	private:
		/***********************************************************************
		 * PRIVATE DATA MEMBER compartments
		 * ---------------------------------------------------------------------
		 * Array of 15 compartments in this shelf.
		 **********************************************************************/
		Compartment compartments[MAX_COMPARTMENTS];
};


#endif /* SHELF_H_ */
