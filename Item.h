#ifndef ITEM_H_
#define ITEM_H_

#include <string>
using namespace std;

class Item
{
	public:
		Item();
		Item(const string& name, const string& description, int id);
		virtual ~Item() = default;
		void setName(const string& name);
		void setDescription(const string& description);
		void setID(int id);
		string getName() const;
		string getDescription() const;
		int getID() const;
		virtual void print(ostream& out) const;
		friend ostream& operator<<(ostream& out, const Item* item);

	private:
		string name;
		string description;
		int id;
};



#endif /* ITEM_H_ */
