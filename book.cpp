#include "Book.h"

Book::Book(const string& description, int id, const string& title, const string& author, const string& copyrightDate)
	:Item(title, description, id), title(title), author(author), copyrightDate(copyrightDate) {
}

void Book::print(ostream& os) const
{
    os << "=== Book ===\n"
        << "Title: " << title << "\n"
        << "Author: " << author << "\n"
        << "Copyright: " << copyrightDate << "\n"
        << "ID: " << id << "\n"
        << "Description: " << description << "\n";

    if (checkedOut) {
        os << "CHECKED OUT\n"
            << "Borrower: " << nameOfUser << "\n"
            << "Due Date: " << dueDate << "\n";
    }
    else {
        os << "In Storage\n";
    }
}
