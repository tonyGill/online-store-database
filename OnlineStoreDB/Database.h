// Database.h

#include <iostream>
#include "Item.h"

namespace Records {

  const int kMaxItems = 100;
  const int kFirstItemNumber = 1000;
  

    class Database
      {
      public:
	Database();
	~Database();

	Item& addItem(std::string incategory, std::string inproductName);
	Item& getItem(int inItemNumber);
	Item& getItem(std::string incategory, std::string inproductName);
	void        displayAll();
	void        displayCurrent();
	void        displayCancelled();
      protected:
	Item    mItems[kMaxItems];
	int         mNextSlot;
	int         mNextItemNumber;
      };
}
