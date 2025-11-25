#ifndef BOOK_H_
#define BOOK_H_

#include "Item.h"

class Book : public Item
{
	public:
		Book();
		Book(const string& description, int id,
			 const string& title, const string& author, const string& copyrightDate);
		void setTitle(string title);
		void setAuthor(string author);
		void setCopyrightDate(string copyrightDate);
		string getTitle() const;
		string getAuthor() const;
		string getCopyrightDate() const;
		void print(ostream& out) const;

	private:
		string title;
		string author;
		string copyrightDate;
};



#endif /* BOOK_H_ */
