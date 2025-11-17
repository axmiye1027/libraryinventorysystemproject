#include "Magazine.h"

Magazine::Magazine(const std::string& name, const std::string& description, int id, const std::string& edition, const std::string& mainArticle)
    : Item(name, description, id),  edition(edition), mainArticle(mainArticle){ }

void Magazine::print(std::ostream& os) const {
    os << "=== Magazine ===\n"
        << "Name: " << name << "\n"
        << "Edition: " << edition << "\n"
        << "Main Article: " << mainArticle << "\n"
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
