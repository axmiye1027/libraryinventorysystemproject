#include "Magazine.h"
#include <iostream>

Magazine::Magazine()
{
	edition = "";
	mainTitle = "";
}

Magazine::Magazine(const string& name, const string& description, int id,
		 	const string& edition, const string& mainTitle) :
		 Item(name, description, id), edition(edition), mainTitle(mainTitle){}

void Magazine::setEdition(const string& edition)
{
	this->edition = edition;
}

void Magazine::setMainTitle(const string& mainTitle)
{
	this->mainTitle = mainTitle;
}

string Magazine::getEdition() const
{
	return edition;
}

string Magazine::getMainTitle() const
{
	return mainTitle;
}

void Magazine::print(ostream& out) const
{
	out << endl;
	out << "Name: " << getName() << std::endl;
	out << "Description: " << getDescription() << std::endl;
	out << "ID: " << getID() << std::endl;
	out << "Edition: " << edition << std::endl;
	out << "Main Title: " << mainTitle << std::endl;
}

