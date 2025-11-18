#include<iostream>
#include<vector>
#include<fstream>
#include "Library.h"
#include "Book.h"
#include "Movie.h"
#include "Magazine.h"

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

	    //Adding items to library
	    library.addItem(book1, 0, 0);
	    library.addItem(book2, 0, 1);
	    library.addItem(movie1, 1, 0);
	    library.addItem(movie2, 1, 1);
	    library.addItem(mag1, 2, 0);
	    library.addItem(mag2, 2, 1);

	    cout << "Print items in library storage:\n";
	    cout << "--------------------------------\n";
	    library.printInventory();
	    cout << endl;

	    //Display Item info using overloaded[] operator
	    cout << "Testing overloaded[] operator - expected item title: \"Great Expectations\"\n";
	    cout << "-------------------------------------------------------------------------\n";
	    cout << library[0][0];
	    cout << endl;

	    //Check out items (all books)
	    ofstream checkoutFile("checkout.txt");

	    library.checkoutItem(checkoutFile, *book1, "Alice Johnson");
	    library.checkoutItem(checkoutFile, *book2, "Bob Williams");

	    checkoutFile.close();
	    cout << endl;

	    //Print inventory after checkout (should be just magazines and movies)
	    cout << "Printing all items in library storage:\n";
	    cout << "-------------------------------------\n";
	    library.printInventory();
	    cout << endl;

	    //Read check out file and print checked-out items
	    cout << "Printing checked-out items from file\n";
	    cout << "------------------------------------\n";
	    ifstream checkoutReadFile("checkout.txt");

	    library.printCheckOutedItems(checkoutReadFile);
	    cout << endl << endl;
	    checkoutReadFile.close();

	    //Checking in items
	    library.checkinItem(*book1);
	    cout << "Printing all items in storage - \"Great Expectations\" should be first\n";
	    cout << "----------------------------------------------------------------------\n";
	    library.printInventory();
	    cout << endl;

	    //Swapping Items
	    cout << "**TESTING SWAPPING ITEMS**\n";
	    cout << "-----------------------\n\n";

	    cout << "Item at library[2][0] before swap:\n";
	    cout << "----------------------------------\n";
	    cout << library[2][0];
	    cout << endl;
	    cout << "Item at library[2][1] before swap:\n";
	    cout << "----------------------------------\n";
	    cout << library[2][1];
	    cout << endl;

	    library.swapItems(2, 0, 2, 1);

	    cout << "Item at library[2][0] after swap:\n";
	    cout << "----------------------------------\n";
	    cout << library[2][0];
	    cout << endl;
	    cout << "Item at library[2][1] after swap:\n";
	    cout << "----------------------------------\n";
	    cout << library[2][1];
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
	    	library.checkoutItem(checkoutFile, *mag1, "David Lee");
	    	library.checkoutItem(checkoutFile, *mag1, "Kevind Dee");
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
	    	library.checkoutItem(checkoutFile, *movie1, "");
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
	    	library.checkinItem(*movie2);
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
