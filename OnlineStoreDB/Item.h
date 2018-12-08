// Item.h

#include <iostream>

namespace Records {
  
  class Item
    {
    public:

      Item();

      void     discount(int indiscountPercent = 100);
      void     add();     // adds a new item or re-add previously added item
      void     cancel();     // Cancels an item
      void     display();  // outputs item info to the console

      // Accessors and setters
      void          setcategory(std::string incategory);
      std::string   getcategory();
      void          setproductName(std::string inproductName);
      std::string   getproductName();
      void          setItemNumber(int inItemNumber);
      int           getItemNumber();
      void          setPrice(int inPrice);
      int           getPrice();
	  bool getIsCancelled();
      bool          getIsAdded();
    private: 
      std::string   mcategory;
      std::string   mproductName;
      int           mItemNumber;
      int           mPrice;
      bool          fAdded;
    };
}
