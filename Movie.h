#include "Item.h"

#ifndef MOVIE_H
#define MOVIE_H

class Movie : public Item
{
private:
	string title;
	string director;
	vector<string> actors;

public:
	Movie(const string& name, const string& description, int id, const string& title, const string& director, const vector<string>& actors);

	void addActor(const string& actor);

	void print(ostream& os) const;
};
#endif
