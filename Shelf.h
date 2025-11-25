#ifndef SHELF_H_
#define SHELF_H_

#include "Item.h"
#include "Book.h"
#include "Magazine.h"
#include "Movie.h"

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

struct Compartment
{
	Item* item = nullptr;
	CheckOutInfo* checkoutInfo = nullptr;
};

const int MAX_COMPARTMENTS = 15;

class Shelf
{
	public:
		Shelf();
		~Shelf();
		Item*& operator[](int index);
		CheckOutInfo*& getCheckOutInfo(int index);

	private:
		Compartment compartments[MAX_COMPARTMENTS];
};


#endif /* SHELF_H_ */
