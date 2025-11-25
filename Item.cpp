#include "Item.h"
#include <iostream>

Item::Item()
{
	name = "";
	description = "";
	id = 0;
}

Item::Item(const string& name, const string& description, int id):
		name(name), description(description), id(id){}

void Item::setName(const string& name)
{
	this->name = name;
}

void Item::setDescription(const string& description)
{
	this->description = description;
}

void Item::setID(int id)
{
	this->id = id;
}

string Item::getName() const
{
	return name;
}

string Item::getDescription() const
{
	return description;
}

int Item::getID() const
{
	return id;
}

void Item::print(ostream& out) const
{
	out << endl;
	out << "Name: " << name << endl;
	out<< "Description: " << description << endl;
	out << "ID: " << id << endl;
}

ostream& operator<<(ostream& out, const Item* item)
{
	item->print(out);
	return out;
}
