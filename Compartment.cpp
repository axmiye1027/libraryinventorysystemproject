#include "Compartment.h"

Compartment::Compartment()
{
	item = nullptr;
	borrowerName = "";
	dueDate = "";
	isCheckedOut = false;
}

Item* Compartment::getItem() const
{
	return item;
}

void Compartment::setItem(Item* newItem)
{
	item = newItem;
}

bool Compartment::isEmpty() const
{
	return item == nullptr;
}

bool Compartment::checkout(const string& borrower, const string& due)
{
	if (isEmpty())
	{
		return false;
	}
	
	if (isCheckedOut)
	{
		return false;
	}

	isCheckedOut = true;
	borrowerName = borrower;
	dueDate = due;
	return true;
}

bool Compartment::checkin()
{
	if (!isCheckedOut)
	{
		return false;
	}

	isCheckedOut = false;
	borrowerName = "";
	dueDate = "";
	return true;
}

bool Compartment::getIsCheckedOut() const
{
	return isCheckedOut;
}

string Compartment::getBorrowerName() const
{
	return borrowerName;
}

string Compartment::getDueDate() const
{
	return dueDate;
}

void Compartment::clear()
{
	item = nullptr;
	borrowerName = "";
	dueDate = "";
	isCheckedOut = false;
}
