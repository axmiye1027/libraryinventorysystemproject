#ifndef LIBRARY_H_
#define LIBRARY_H_

#include "Shelf.h"

class Library
{
	public:
		Library();
		Library(int numOfShelves);
		~Library();
		Shelf& operator[](int index);
		bool addItem(Item* item, int shelf, int compartment);
		bool checkOutItem(CheckOutInfo* info, int shelf, int compartment);
		bool checkInItem(int id, int shelf, int compartment);
		void printItemsInStorage(ostream& out);
		void printCheckOutItems(ostream& out);
		bool swapItems(int shelf1, int compartment1, int shelf2, int compartment2);
		void addShelves(int numOfShelves);

	private:
		vector<Shelf> shelves;
		void validateShelf(int shelf);
		void validateCompartment(int shelf, int comp);
};



#endif /* LIBRARY_H_ */
