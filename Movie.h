#ifndef MOVIE_H_
#define MOVIE_H_

#include "Item.h"
#include <vector>

class Movie : public Item
{
	public:
		Movie();
		Movie(const string& description, int id,
			  const string& title, const string& director, const vector<string>& actorList);
		void setTitle(const string& title);
		void setDirector(const string& director);
		void setActorList(const vector<string>& actorList);
		string getTitle() const;
		string getDirector() const;
		vector<string> getActorList() const;
		void print(ostream& out) const;

	private:
		string title;
		string director;
		vector<string> actorList;
};




#endif /* MOVIE_H_ */
