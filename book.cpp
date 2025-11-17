#include "book.h"

Book::Book(const string& name, const string& description, int id, const string& title, const string& author, const string& copyrightDate)
	:Item(name, description, id), title(title), author(author), copyrightDate(copyrightDate) {
}

void Book::print(ostream& os) const
{
    os << "=== Book ===\n"
        << "Name: " << name << "\n"
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
