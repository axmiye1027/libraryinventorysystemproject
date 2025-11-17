
#include "Item.h"

#ifndef BOOK_H
#define BOOK_H

class Book : public Item
{
private:
	string title;
	string author;
	string copyrightDate;
public:
	Book(const string& name, const string& description, int id, const string& title, const string& author, const string& copyrightDate);

	void print(ostream& os) const override;
};
#endif
