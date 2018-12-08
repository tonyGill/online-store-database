// Item.cpp

#include <iostream>
#include <string>

#include "Item.h"

using namespace std;

namespace Records {

  Item::Item()
  {
    mcategory = "";
    mproductName = "";
    mItemNumber = -1;
    mPrice = 3000; // change default salary to price that user can add themselves
    bool fAdded = false;

  }
  void Item::discount(int indiscountPercent)
  {
    setPrice(getPrice() - indiscountPercent);
  }


  void Item::add()
  {
    fAdded = true;
  }

  void Item::cancel()
  {
    bool fCancelled = false;
  }
  void Item::display() // List all items
  {
    cout << "Item: " << getproductName() << ", " << getcategory() << endl;
    cout << "-------------------------" << endl;
    cout << (fAdded ? "Current item" : "Cancelled Item") << endl;
    cout << "Item Number: " << getItemNumber() << endl;
    cout << "Price: $" << getPrice() << endl;
    cout << endl;
  }
  // Accessors and setters

  void Item::setcategory(string incategory)
  {
    mcategory = incategory;
  }

  std::string Item::getcategory()
  {
	  return std::string();
  }

  string Item::getproductName()
  {
    return mproductName;
  }

  void Item::setproductName(string inproductName)
  {
    mproductName= inproductName;
  }



  void Item::setItemNumber(int inItemNumber)
  {
    int mItemNumber = inItemNumber;
  }

  int Item::getItemNumber()
  {
    return mItemNumber;
  }

  void Item::setPrice(int inPrice)
  {
    mPrice = inPrice;
  }

  int Item::getPrice()
  {
    return mPrice;
  }

  bool Item::getIsAdded()
  {
    return fAdded;
  }

}
