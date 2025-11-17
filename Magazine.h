

#include "Item.h"

#ifndef MAGAZINE_H
#define MAGAZINE_H

class Magazine : public Item
{
private:
	string edition;
	string mainArticle;
public:
	Magazine(const string& name, const string& description, int id, const string& edition, const string& mainArticle);

	void print(ostream& os) const override;
};
#endif
