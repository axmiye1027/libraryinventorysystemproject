#include "Shelf.h"
#include <stdexcept>

Shelf::Shelf()
{
	for(int i = 0; i < MAX_COMPARTMENTS; i++)
	{
		compartments[i].item = nullptr;
		compartments[i].checkoutInfo = nullptr;
	}
}

Shelf::~Shelf()
{
	for(int i = 0; i < MAX_COMPARTMENTS; i++)
	{
		delete compartments[i].item;
		compartments[i].item = nullptr;

		delete compartments[i].checkoutInfo;
		compartments[i].checkoutInfo = nullptr;
	}
}

Item*& Shelf::operator[](int index)
{
	if(index < 0 || index >= MAX_COMPARTMENTS)
	{
		throw out_of_range("Invalid compartment index\n");
	}

	return compartments[index].item;
}

CheckOutInfo*& Shelf::getCheckOutInfo(int index)
{
	if(index < 0 || index >= MAX_COMPARTMENTS)
	{
		throw out_of_range("Invalid compartment index\n");
	}

	return compartments[index].checkoutInfo;
}
