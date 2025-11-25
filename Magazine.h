#ifndef MAGAZINE_H_
#define MAGAZINE_H_

#include "Item.h"

class Magazine : public Item
{
	public:
		Magazine();
		Magazine(const string& name, const string& description, int id,
				 const string& editition, const string& mainTitle);
		void setEdition(const string& edition);
		void setMainTitle(const string& mainTitle);
		string getEdition() const;
		string getMainTitle() const;
		void print(ostream& out) const;

	private:
		string edition;
		string mainTitle;
};



#endif /* MAGAZINE_H_ */
