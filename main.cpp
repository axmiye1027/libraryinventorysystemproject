#include "Library.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    cout << "========================================\n";
    cout << "Library Inventory System Test\n";
    cout << "========================================\n\n";

    // Create library instance
    Library library;

    // ============================================
    // TEST 1: Add items to storage
    // ============================================
    cout << "TEST 1: Adding items to storage...\n";
    cout << "----------------------------------------\n";

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

    // Add items to library
    library.addItem(*book1);
    library.addItem(*book2);
    library.addItem(*movie1);
    library.addItem(*movie2);
    library.addItem(*mag1);
    library.addItem(*mag2);

    cout << "Successfully added 6 items to the library.\n\n";

    // ============================================
    // TEST 2: Print initial inventory
    // ============================================
    cout << "TEST 2: Printing initial inventory...\n";
    cout << "----------------------------------------\n";
    library.printInventory();
    cout << "\n";

    // ============================================
    // TEST 3: Check out items
    // ============================================
    cout << "TEST 3: Checking out items...\n";
    cout << "----------------------------------------\n";

    // Open checkout file for writing
    ofstream checkoutFile("checkout.txt");
    if (!checkoutFile)
    {
        cerr << "Error: Could not open checkout.txt for writing.\n";
        return 1;
    }

    // Check out some items
    library.checkoutItem(checkoutFile, *book1, "Alice Johnson");
    cout << "Checked out: " << book1->getName() << " to Alice Johnson\n";

    library.checkoutItem(checkoutFile, *movie1, "Bob Williams");
    cout << "Checked out: " << movie1->getName() << " to Bob Williams\n";

    library.checkoutItem(checkoutFile, *mag1, "Charlie Brown");
    cout << "Checked out: " << mag1->getName() << " to Charlie Brown\n";

    checkoutFile.close();
    cout << "\n";

    // ============================================
    // TEST 4: Print inventory after checkout
    // ============================================
    cout << "TEST 4: Printing inventory after checkout...\n";
    cout << "----------------------------------------\n";
    library.printInventory();
    cout << "\n";

    // ============================================
    // TEST 5: Print checked-out items from file
    // ============================================
    cout << "TEST 5: Printing checked-out items from file...\n";
    cout << "----------------------------------------\n";
    ifstream checkoutReadFile("checkout.txt");
    if (checkoutReadFile)
    {
        library.printCheckOutedItems(checkoutReadFile);
        checkoutReadFile.close();
    }
    else
    {
        cerr << "Error: Could not open checkout.txt for reading.\n";
    }
    cout << "\n";

    // ============================================
    // TEST 6: Check in items
    // ============================================
    cout << "TEST 6: Checking in items...\n";
    cout << "----------------------------------------\n";
    
    library.checkinItem(*book1);
    cout << "Checked in: " << book1->getName() << "\n";

    library.checkinItem(*movie1);
    cout << "Checked in: " << movie1->getName() << "\n";
    cout << "\n";

    // ============================================
    // TEST 7: Print inventory after check-in
    // ============================================
    cout << "TEST 7: Printing inventory after check-in...\n";
    cout << "----------------------------------------\n";
    library.printInventory();
    cout << "\n";

    // ============================================
    // TEST 8: Swap items operation
    // ============================================
    cout << "TEST 8: Performing swap operations...\n";
    cout << "----------------------------------------\n";
    
    // Swap items at different positions
    cout << "Swapping item at [0][0] with item at [1][0]...\n";
    library.swapItems(0, 0, 1, 0);
    cout << "Swap successful.\n\n";

    cout << "Inventory after swap:\n";
    library.printInventory();
    cout << "\n";

    // Swap back
    cout << "Swapping back: [1][0] with [0][0]...\n";
    library.swapItems(1, 0, 0, 0);
    cout << "Swap successful.\n\n";

    // ============================================
    // TEST 9: Error handling demonstrations
    // ============================================
    cout << "TEST 9: Error handling demonstrations...\n";
    cout << "----------------------------------------\n";

    // Error 1: Try to check out an already checked out item
    cout << "Error Test 1: Attempting to check out an already checked-out item...\n";
    checkoutFile.open("checkout.txt", ios::app);
    library.checkoutItem(checkoutFile, *mag1, "David Lee");
    checkoutFile.close();
    cout << "\n";

    // Error 2: Try to check in an item that's not checked out
    cout << "Error Test 2: Attempting to check in an item that's not checked out...\n";
    library.checkinItem(*book2);
    cout << "\n";

    // Error 3: Try to swap with invalid indices (this will cause undefined behavior/crash)
    // We'll demonstrate this with a comment and a safer approach would be to add bounds checking
    cout << "Error Test 3: Attempting swap with invalid indices...\n";
    cout << "Note: Current implementation does not validate indices.\n";
    cout << "Swapping [0][0] with [10][10] (invalid indices)...\n";
    // Uncomment the line below to see the crash:
    // library.swapItems(0, 0, 10, 10);  // This would cause undefined behavior
    cout << "(Skipped to prevent crash - would need bounds checking in swapItems)\n\n";

    // ============================================
    // TEST 10: Final inventory state
    // ============================================
    cout << "TEST 10: Final inventory state...\n";
    cout << "----------------------------------------\n";
    library.printInventory();
    cout << "\n";

    cout << "========================================\n";
    cout << "All tests complete.\n";
    cout << "========================================\n";

    // Cleanup: Library destructor will handle deleting items
    return 0;
}
