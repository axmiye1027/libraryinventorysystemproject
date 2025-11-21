/***************************************************************************
 * AUTHOR			: Amy X, Ryland L, Cristal D, Elizabeth S, Paul S.
 * PROJECT #2		: Library Inventory System
 * CLASS			: CS 1C
 * SECTION			: TTh 8a
 * DUE DATE			: ...
 **************************************************************************/

#ifndef SHELF_H
#define SHELF_H

#include <iostream>
#include <stdexcept>
#include "Compartment.h"

using namespace std;

/***************************************************************************
 * CLASS Shelf
 * -------------------------------------------------------------------------
 * Represents a single shelf containing 15 compartments.
 **************************************************************************/
class Shelf
{
private:
	/***********************************************************************
	 * PRIVATE DATA MEMBER compartments
	 * ---------------------------------------------------------------------
	 * Array of 15 compartments in this shelf.
	 **********************************************************************/
	static const int MAX_COMPARTMENTS = 15;
	Compartment compartments[MAX_COMPARTMENTS];

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
	 * Compartments clean themselves up.
	 **********************************************************************/
	~Shelf() = default;

	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION []
	 * ---------------------------------------------------------------------
	 * Overloads the [] operator to access compartments by index.
	 * Throws exception if index is out of bounds.
	 * ---------------------------------------------------------------------
	 * => Returns reference to Compartment at index
	 **********************************************************************/
	Compartment& operator[](int index);

	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION getCompartment (const version)
	 * ---------------------------------------------------------------------
	 * Returns const reference to compartment at index.
	 * ---------------------------------------------------------------------
	 * => Returns const reference to Compartment at index
	 **********************************************************************/
	const Compartment& operator[](int index) const;

	/***********************************************************************
	 * PUBLIC MEMBER FUNCTION getMaxCompartments
	 * ---------------------------------------------------------------------
	 * Returns the maximum number of compartments per shelf.
	 * ---------------------------------------------------------------------
	 * => Returns MAX_COMPARTMENTS constant
	 **********************************************************************/
	static int getMaxCompartments();
};

#endif
