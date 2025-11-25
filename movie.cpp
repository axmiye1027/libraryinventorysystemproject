#include "Movie.h"
#include <iostream>

Movie::Movie()
{
	title = "";
	director = "";
}

Movie::Movie(const string& description, int id, const string& title,
			 const string& director, const vector<string>& actorList) :
	 Item(title, description, id), title(title), director(director),
	 actorList(actorList){}

void Movie::setTitle(const string& title)
{
	this->title = title;
}

void Movie::setDirector(const string& director)
{
	this->director = director;
}

void Movie::setActorList(const vector<string>& actorList)
{
	this->actorList = actorList;
}

string Movie::getTitle() const
{
	return title;
}

string Movie::getDirector() const
{
	return director;
}

vector<string> Movie::getActorList() const
{
	return actorList;
}

void Movie::print(ostream& out) const
{
	out << endl;
	out << "Title: " << title << std::endl;
	out << "Description: " << getDescription() << std::endl;
	out << "ID: " << getID() << std::endl;
	out << "Director: " << director << std::endl;

	out << "List of actors: ";

	bool first = true;

	for(auto const& a : actorList)
	{
		if(!first)
		{
			out << ", ";
		}

		out << a;

		first = false;
	}

	out << endl;

}
