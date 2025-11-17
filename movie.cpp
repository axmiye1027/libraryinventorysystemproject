#include "Movie.h"

Movie::Movie(const string& name, const string& description, int id, const string& title, const string& director, const vector<string>& actors)
	: Item(name, description, id), title(title), director(director), actors(actors) {
}

void Movie::addActor(const string& actor)
{
		this->actors.push_back(actor);
}

void Movie::print(ostream& os) const
{
    os << "=== Movie ===\n"
        << "Name: " << name << "\n"
        << "Title: " << title << "\n"
        << "Director: " << director << "\n"
        << "ID: " << id << "\n"
        << "Description: " << description << "\n"
        << "Main Actors: ";

    for (size_t i = 0; i < actors.size(); ++i) {
        os << actors[i];
        if (i + 1 < actors.size()) os << ", ";
    }
    os << "\n";

    if (checkedOut) {
        os << "CHECKED OUT\n"
            << "Borrower: " << nameOfUser << "\n"
            << "Due Date: " << dueDate << "\n";
    }
    else {
        os << "In Storage\n";
    }
}
