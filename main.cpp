#include <iostream>
#include <vector>
#include <fstream>
#include "Library.h"
#include "Book.h"
#include "Movie.h"
#include "Magazine.h"
#include "Shelf.h"
#include "Compartment.h"

using namespace std;

int main()
{
    cout << "========================================\n";
    cout << "Library Inventory System\n";
    cout << "========================================\n\n";

	try
	{
		Library library(3);

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
	    library.addItem(book1, 0, 0);
	    cout << "Added: \"" << book1->getName() << "\" to Shelf " << 0 << ", Compartment " << 0 << endl;
	    library.addItem(book2, 0, 1);
	    cout << "Added: \"" << book2->getName() << "\" to Shelf " << 0 << ", Compartment " << 1 << endl;
	    library.addItem(movie1, 1, 0);
	    cout << "Added: \"" << movie1->getName() << "\" to Shelf " << 1 << ", Compartment " << 0 << endl;
	    library.addItem(movie2, 1, 1);
	    cout << "Added: \"" << movie2->getName() << "\" to Shelf " << 1 << ", Compartment " << 1 << endl;
	    library.addItem(mag1, 2, 0);
	    cout << "Added: \"" << mag1->getName() << "\" to Shelf " << 2 << ", Compartment " << 0 << endl;
	    library.addItem(mag2, 2, 1);
	    cout << "Added: \"" << mag2->getName() << "\" to Shelf " << 2 << ", Compartment " << 1 << endl;
	    cout << endl;

	    // SYSTEM OPERATION 2: Checkout an Item
	    cout << "2. CHECKING OUT ITEMS\n";
	    cout << "======================\n";
	    ofstream checkoutFile("checkout.txt");
	    library.checkoutItem(checkoutFile, 0, 0, "Alice Johnson");
	    Item* checkedOut1 = library[0][0].getItem();
	    if(checkedOut1 != nullptr)
	    {
	    	cout << "\"" << checkedOut1->getName() << "\" checked out by: Alice Johnson" << endl;
	    }
	    library.checkoutItem(checkoutFile, 0, 1, "Bob Williams");
	    Item* checkedOut2 = library[0][1].getItem();
	    if(checkedOut2 != nullptr)
	    {
	    	cout << "\"" << checkedOut2->getName() << "\" checked out by: Bob Williams" << endl;
	    }
	    checkoutFile.close();
	    cout << endl;

	    // SYSTEM OPERATION 3: Checkin an Item
	    cout << "3. CHECKING IN ITEMS\n";
	    cout << "=====================\n";
	    // Get borrower name before checkin
	    string borrowerName = library[0][0].getBorrowerName();
	    Item* returnedItem = library[0][0].getItem();
	    library.checkinItem(0, 0);
	    if(returnedItem != nullptr)
	    {
	    	cout << borrowerName << " returned: \"" << returnedItem->getName() << "\"" << endl;
	    	cout << "Item placed back in Shelf " << 0 << ", Compartment " << 0 << endl;
	    }
	    cout << endl;

	    // SYSTEM OPERATION 4: Print Items in Storage
	    cout << "4. PRINTING ITEMS IN STORAGE\n";
	    cout << "=============================\n";
	    library.printInventory();
	    cout << endl;

	    // SYSTEM OPERATION 5: Print Checked-Out Items
	    cout << "5. PRINTING CHECKED-OUT ITEMS\n";
	    cout << "==============================\n";
	    library.printCheckedOutItems();
	    cout << endl;

	    // SYSTEM OPERATION 6: Swap Items
	    cout << "6. SWAPPING ITEMS\n";
	    cout << "==================\n";
	    // Get item names before swap
	    Item* swapItem1 = library[2][0].getItem();
	    Item* swapItem2 = library[2][1].getItem();
	    string item1Name = (swapItem1 != nullptr) ? swapItem1->getName() : "Unknown";
	    string item2Name = (swapItem2 != nullptr) ? swapItem2->getName() : "Unknown";
	    library.swapItems(2, 0, 2, 1);
	    cout << "Swapped: \"" << item1Name << "\" (Shelf " << 2 << ", Compartment " << 0 << ") ";
	    cout << "with \"" << item2Name << "\" (Shelf " << 2 << ", Compartment " << 1 << ")" << endl;
	    cout << endl;

	    cout << "**TESTING ERROR HANDLING**\n";
	    cout << "---------------------------\n";

	    //Error Handling - adding to invalid compartment
	    Book* testBook = new Book("Test", 0, "Test", "NULL", "NULL");
	    try
	    {
	    	library.addItem(testBook, 6, 0);
	    }
	    catch(const exception& e)
	    {
	    	cout << "Expected exception: invalid row\n";
	    	cout << "Actual: " <<  e.what() << endl << endl;
	    }

	    //Error Handling - adding to invalid row
	    try
	    {
	    	library.addItem(testBook, 2, 16);
	    }
	    catch(const exception& e)
	    {
	    	cout << "Expected exception: invalid column/compartment\n";
	    	cout << "Actual: " <<  e.what() << endl << endl;
	    	delete testBook;
	    }

	    //Error Handling - swapping with empty compartment
	    try
	    {
	    	library.swapItems(0, 0, 0, 13);
	    }
	    catch(const exception& e)
	    {
	    	cout << "Expected exception: cannot swap with empty compartment\n";
	    	cout << "Actual: " <<  e.what() << endl << endl;
	    }

	    //Error Handling - checking out item that is already checked out
	    try
	    {
	    	checkoutFile.open("checkout.txt", ios::app);
	    	library.checkoutItem(checkoutFile, 2, 0, "David Lee");
	    	library.checkoutItem(checkoutFile, 2, 0, "Kevind Dee");
	    }
	    catch(const exception& e)
	    {
	    	cout << "Expected exception: item is already checked out\n";
	    	cout << "Actual: " <<  e.what() << endl << endl;
	    	checkoutFile.close();
	    }

	    //Error Handling - checking out item with blank name
	    try
	    {
	    	checkoutFile.open("checkout.txt", ios::app);
	    	library.checkoutItem(checkoutFile, 1, 0, "");
	    }
	    catch(const exception& e)
	    {
	    	cout << "Expected exception: cannot check out item with blank name\n";
	    	cout << "Actual: " <<  e.what() << endl << endl;
	    	checkoutFile.close();
	    }

	    //Error Handling - checking in item that was not checked out
	    try
	    {
	    	library.checkinItem(1, 1);
	    }
	    catch(const exception& e)
	    {
	    	cout << "Expected exception: cannot check in item that hasn't been check out\n";
	    	cout << "Actual: " <<  e.what() << endl << endl;
	    }

	    //Error Handling - accessing invalid shelf
	    try
	    {
	    	library[100];
	    }
	    catch(const exception& e)
	    {
	    	cout << "Expected exception: cannot access invalid row\n";
	    	cout << "Actual: " <<  e.what() << endl << endl;
	    }

	}
	catch(const exception& e)
	{
		cout << "Exception error: " << e.what() << endl;
	}
}
