
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#ifndef ITEM_H
#define ITEM_H

class Item
{
protected:
	string name;
	string description;
	int id;
	bool checkedOut;
	string nameOfUser;
	string dueDate;
public:

	Item(const string& name, const string& description, int id);

	virtual ~Item() = default;

	int getID() const;
	string getName() const;
	string getDescription() const;

	bool isCheckedOut() const;
	string getBorrowerName() const;
	string getDueDate() const;

	bool checkout(const string& person, const string& due);
	bool checkin();

	virtual void print(ostream& os) const = 0;

	friend ostream& operator<< (ostream & os, const Item& item);
};


#endif
