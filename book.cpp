#include "Book.h"
#include <iostream>

Book::Book()
{
	title = "";
	author = "";
	copyrightDate = "";
}

Book::Book(const string& description, int id,
		   const string& title, const string& author, const string& copyrightDate):
			Item(title, description, id), title(title), author(author),
			copyrightDate(copyrightDate){}

void Book::setTitle(string title)
{
	this->title = title;
}

void Book::setAuthor(string author)
{
	this->author = author;
}

void Book::setCopyrightDate(string copyrightDate)
{
	this->copyrightDate = copyrightDate;
}

string Book::getTitle() const
{
	return title;
}

string Book::getAuthor() const
{
	return author;
}

string Book::getCopyrightDate() const
{
	return copyrightDate;
}

void Book::print(ostream& out) const
{
	out << endl;
	out << "Title: " 		  << title 		 	   << std::endl;
	out << "Description: " 	  << getDescription()  << std::endl;
	out << "ID: " 		 	  << getID()		   << std::endl;
	out << "Author: " 	 	  << author 		   << std::endl;
	out << "Copyright Date: " << copyrightDate 	   << std::endl;
}

