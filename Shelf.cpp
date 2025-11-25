#include "Shelf.h"

Shelf::Shelf()
{
	// Compartments are default-constructed as empty
}

Compartment& Shelf::operator[](int index)
{
	if (index < 0 || index >= MAX_COMPARTMENTS)
	{
		throw out_of_range("Invalid compartment index");
	}
	return compartments[index];
}

const Compartment& Shelf::operator[](int index) const
{
	if (index < 0 || index >= MAX_COMPARTMENTS)
	{
		throw out_of_range("Invalid compartment index");
	}
	return compartments[index];
}

int Shelf::getMaxCompartments()
{
	return MAX_COMPARTMENTS;
}
