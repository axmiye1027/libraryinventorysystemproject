#include "Item.h"

Item::Item(const string& name, const string& description, int id)
{
	this->name = name;
	this->description = description;
	this->id = id;
	checkedOut = false;
	nameOfUser = "";
	dueDate = "";
}

int Item::getID() const
{
	return id;
}
string Item::getName() const
{
	return name;
}

string Item::getDescription() const
{
	return description;
}

bool Item::isCheckedOut() const
{
	return checkedOut;
}
string Item::getBorrowerName() const
{
	return nameOfUser;
}
string Item::getDueDate() const
{
	return dueDate;
}

bool Item::checkout(const string& person, const string& due)
{
	if (checkedOut)
	{
		cout << "Error----- " << name << "is already checked out.\n";
		return false;
	}
	checkedOut = true;
	nameOfUser = person;
	dueDate = due;
	return true;
}
bool Item::checkin()
{
	if (!checkedOut) {
		cout << "Error--------" << name << " is not currently checked out.\n";
		return false;
	}
	checkedOut = false;
	nameOfUser.clear();
	dueDate.clear();
	return true;
}

ostream& operator << (ostream& os, const Item& item)
{
	item.print(os);
	return os;
}
