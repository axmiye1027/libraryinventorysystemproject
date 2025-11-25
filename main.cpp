#include "Item.h"
#include "Book.h"
#include "Magazine.h"
#include "Movie.h"
#include "Shelf.h"
#include "Library.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "========================================\n";
    cout << "Library Inventory System\n";
    cout << "========================================\n\n";

	try
	{
		Library libraryInventory(3);

	    // Create books
	    Book* book1 = new Book("Dickens's classic novel", 1001,
	                          "Great Expectations", "Charles Dickens", "1861");
	    Book* book2 = new Book("Winner of the Pulitzer Prize for Fiction", 1002,
	                          "To Kill a Mockingbird", "Harper Lee", "1960");

	    // Create movies
	    vector<string> actors1 = {"Arnold Schwarzenegger", "Linda Hamilton", "Michael Biehn"};
	    Movie* movie1 = new Movie("The classic action film that started the Terminator franchise", 2001,
	                             "The Terminator", "James Cameron", actors1);

	    vector<string> actors2 = {"Elijah Wood", "Ian McKellen", "Viggo Mortensen"};
	    Movie* movie2 = new Movie("The classic fantasy film that started the Lord of the Rings franchise", 2002,
	                             "The Lord of the Rings", "Peter Jackson", actors2);

	    // Create magazines
	    Magazine* mag1 = new Magazine("Wired", "Covering the latest in technology and science", 3001,
	                                 "January 2024", "AI Revolution");
	    Magazine* mag2 = new Magazine("The New York Times", "All the news that's fit to print", 3002,
	                                 "February 2024", "Global Economy");

	    // SYSTEM OPERATION 1: Add an Item
	    cout << "1. ADDING ITEMS TO LIBRARY\n";
	    cout << "===========================\n";
	    libraryInventory.addItem(book1, 0, 0);
	    cout << "Added: \"" << libraryInventory[0][0]->getName() << "\" to Shelf " << 0 << ", Compartment " << 0 << endl;
	    libraryInventory.addItem(book2, 0, 1);
	    cout << "Added: \"" << libraryInventory[0][1]->getName() << "\" to Shelf " << 0 << ", Compartment " << 1 << endl;
	    libraryInventory.addItem(movie1, 1, 0);
	    cout << "Added: \"" << libraryInventory[0][0]->getName() << "\" to Shelf " << 1 << ", Compartment " << 0 << endl;
	    libraryInventory.addItem(movie2, 1, 1);
	    cout << "Added: \"" << libraryInventory[1][1]->getName() << "\" to Shelf " << 1 << ", Compartment " << 1 << endl;
	    libraryInventory.addItem(mag1, 2, 0);
	    cout << "Added: \"" << libraryInventory[2][0]->getName() << "\" to Shelf " << 2 << ", Compartment " << 0 << endl;
	    libraryInventory.addItem(mag2, 2, 1);
	    cout << "Added: \"" << libraryInventory[2][1]->getName() << "\" to Shelf " << 2 << ", Compartment " << 1 << endl;
	    cout << endl;


	    // SYSTEM OPERATION 2: Checkout an Item
	    cout << "2. CHECKING OUT ITEMS\n";
	    cout << "======================\n";

	    cout << "Valid Checkout attempt: #1 - Mary Berry\n";
	    CheckOutInfo* infoPtr1 = new CheckOutInfo("Mary Berry", "October 3rd, 2026");
	    if(libraryInventory.checkOutItem(infoPtr1, 0, 0))
	    {
	    	cout << "Check out successful\n";
	    	cout << libraryInventory[0].getCheckOutInfo(0)->name << " checked out Item:";
	    	cout << libraryInventory[0][0];
	    	cout << "**Item is due: ";
	    	cout << libraryInventory[0].getCheckOutInfo(0)->dueDate << endl;
	    	cout << endl;
	    }
	    else
	    {
	    	cout << "Check out unsuccessful: Either empty item or item is already checked out.\n";
	    }

	    cout << "Valid Checkout attempt: #2 - Luis Gomez\n";
	    CheckOutInfo* infoPtr2 = new CheckOutInfo("Luis Gomez", "December 3rd, 2025");
	    if(libraryInventory.checkOutItem(infoPtr2, 2, 0))
	    {
	    	cout << "Check out successful\n";
	    	cout << libraryInventory[2].getCheckOutInfo(0)->name << " checked out Item:";
	    	cout << libraryInventory[2][0];
	    	cout << "**Item is due: ";
	    	cout << libraryInventory[2].getCheckOutInfo(0)->dueDate << endl;
	    	cout << endl;
	    }
	    else
	    {
	    	cout << "Check out unsuccessful: Either empty item or item is already checked out.\n";
	    }

	    cout << "Invalid Checkout attempt: #1 - Julia Smith\n";
	    cout << "Attempting to check out item already checked out\n";
	    CheckOutInfo* infoPtr3 = new CheckOutInfo("Julia Smith", "December 2nd, 2025");
	    if(libraryInventory.checkOutItem(infoPtr3, 2, 0))
	    {
	    	cout << "Check out successful\n";
	    	cout << libraryInventory[2].getCheckOutInfo(0)->name << " checked out Item:";
	    	cout << libraryInventory[2][0];
	    	cout << "**Item is due: ";
	    	cout << libraryInventory[2].getCheckOutInfo(0)->dueDate << endl;
	    	cout << endl;
	    }
	    else
	    {
	    	cout << "Check out unsuccessful: Either empty item or item is already checked out.\n";
	    	cout << endl;
	    }


	    //Print Items checked out
	    cout << "PRINTING OUT CHECKED OUT ITEMS\n";
	    cout << "======================\n";
	    libraryInventory.printCheckOutItems(cout);

	    //Print Items in storage
	    cout << "PRINTING OUT ITEMS IN STORAGE\n";
	    cout << "======================\n";
	    libraryInventory.printItemsInStorage(cout);

	    // SYSTEM OPERATION 3: Checkin an Item
	    cout << "3. CHECKING IN ITEMS\n";
	    cout << "=====================\n";
	    cout << "Testing checking in item with ID: 1001 at Shelf 0, Compartment 0.\n";

	    //Testing invalid check in - ID incorrect
	    cout << "Testing checking in item with incorrect ID: 2000\nRESULT:";
	    if(!libraryInventory.checkInItem(2000, 0, 0))
	    {
	    	cout << "Checkout unsuccessful: either ID or compartment is incorrect.\n";
	    	cout << endl;
	    }

	    //Testing invalid check in - Compartment incorrect
	    cout << "Testing checking in item with incorrect compartment location 0, 1\nRESULT:";
	    if(!libraryInventory.checkInItem(1001, 0, 1))
	    {
	    	cout << "Checkout unsuccessful: either ID or compartment is incorrect.\n";
	    	cout << endl;
	    }

	    //Checking in item with correct ID and in correct compartment
	    cout << "Testing checking in item with correct ID and compartment location\nRESULT:";
	    if(libraryInventory.checkInItem(1001, 0, 0))
	    {
	    	cout << "Checkout successful!\n";
	    	cout << "Item with ID number: " << libraryInventory[0][0]->getID();
	    	cout << " has been checked in.\n";
	    	cout << endl;
	    }

	    //Testing invalid checkout - checking in an item that has not been checked out
	    cout << "Testing checking in item that has not been checked out\nRESULT:";
	    if(!libraryInventory.checkInItem(2002, 1, 1))
	    {
	    	cout << "Checkout unsuccessful: Item has not been checked out.\n";
	    	cout << endl;
	    }

	    // SYSTEM OPERATION 4: Print Items in Storage
	    cout << "4. PRINTING ITEMS IN STORAGE\n";
	    cout << "=============================\n";
	    libraryInventory.printItemsInStorage(cout);

	    // SYSTEM OPERATION 5: Print Checked-Out Items
	    cout << "5. PRINTING CHECKED-OUT ITEMS\n";
	    cout << "==============================\n";
	    libraryInventory.printCheckOutItems(cout);
	    cout << endl;

	    // SYSTEM OPERATION 6: Swap Items
	    cout << "6. SWAPPING ITEMS\n";
	    cout << "==================\n";

	    cout << "Item in shelf 0, compartment 0 before swap:\n";
	    cout << "*********************************************";
	    cout << libraryInventory[0][0];
	    cout << endl;
	    cout << "Item in shelf 2, compartment 1 before swap:\n";
	    cout << "*********************************************";
	    cout << libraryInventory[2][1];

	    if(libraryInventory.swapItems(0, 0, 2, 1))
	    {
	    	cout << "\nItems have been swapped\n\n";
	    }
	    else
	    {
	    	cout << "Items have not been swapped\n";
	    	cout << "Items in the compartments are either empty or checked out.\n";
	    }

	    cout << "Item in shelf 0, compartment 0 after swap:\n";
	    cout << "*********************************************";
	    cout << libraryInventory[0][0];
	    cout << endl;
	    cout << "Item in shelf 2, compartment 1 after swap:\n";
	    cout << "*********************************************";
	    cout << libraryInventory[2][1];

	    //Attempting to swap with an empty compartment
	    cout << "\nAttempting to swap with an empty item compartment.\nResult:";
	    if(!libraryInventory.swapItems(0, 0, 0, 13))
	    {
	    	cout << "Cannot swap with empty compartment\n";
	    }

	    // Error Handling - Edge cases
	    cout << "\nError Handling\n";
	    cout << "==================\n";
	    Book* testBook = new Book("Test", 0, "Test", "NULL", "NULL");

	    //Adding to invalid shelf
	    try
	    {
	    	libraryInventory.addItem(testBook, 30, 0);
	    }
	    catch(const exception& e)
	    {
	    	cout << "Expected exception: invalid shelf\n";
	    	cout << "Actual: " <<  e.what() << endl << endl;
	    }

	    //Adding to invalid compartment
	    try
	    {
	    	libraryInventory.addItem(testBook, 2, 20);
	    }
	    catch(const exception& e)
	    {
	    	cout << "Expected exception: invalid compartment\n";
	    	cout << "Actual: " <<  e.what() << endl << endl;
	    	delete testBook;
	    }

	    //Checking out an empty item
	    try
	    {
	    	libraryInventory.checkOutItem(infoPtr3, 2, 13);
	    }
	    catch(const exception& e)
	    {
	    	cout << "Expected exception: cannot check out an empty item\n";
	    	cout << "Actual: " << e.what() << endl << endl;
	    	delete infoPtr3;
	    }

	    //Checking out Item with no borrower information provided
	    try
	    {
	    	libraryInventory.checkOutItem(nullptr, 0, 0);
	    }
	    catch(const exception& e)
	    {
	    	cout << "Expected exception: Information cannot be blank\n";
	    	cout << "Actual: " << e.what() << endl << endl;
	    }

	    //Checking out Item with empty name string and empty due date
	    try
	    {
	    	CheckOutInfo* infoPtr = new CheckOutInfo("","");
	    	libraryInventory.checkOutItem(infoPtr, 0, 0);
	    }
	    catch(const exception& e)
	    {
	    	cout << "Expected exception: Name nor due date cannot be blank\n";
	    	cout << "Actual: " << e.what() << endl << endl;
	    }

	    //Accessing invalid shelf
	    try
	    {
	    	libraryInventory[100][0];
	    }
	    catch(const exception& e)
	    {
	    	cout << "Expected exception: cannot access invalid shelf\n";
	    	cout << "Actual: " <<  e.what() << endl << endl;
	    }

	    //Accessing invalid compartment
	    try
	    {
	    	libraryInventory[0][17];
	    }
	    catch(const exception& e)
	    {
	    	cout << "Expected exception: cannot access invalid compartment\n";
	    	cout << "Actual: " <<  e.what() << endl << endl;
	    }

	}
	catch(const exception& e)
	{
		cout << "Exception error: " << e.what() << endl;
	}

	return 0;
}


