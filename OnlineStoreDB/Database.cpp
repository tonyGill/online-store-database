// Database.cpp

#include <iostream>
#include <stdexcept>
#include <string>

#include "Database.h"

using namespace std;

namespace Records {

  Database::Database()
  {
    mNextSlot = 0;
    mNextItemNumber = kFirstItemNumber;
	
  }
  Database::~Database()
  {
  }
  Item& Database::addItem(string incategory, string inproductName)
  {
    if (mNextSlot >= kMaxItems) {
      cerr << "There is no more room to add any new items!" << endl;
      throw exception();
    }

    Item& theItem= mItems[mNextSlot++];
    theItem.setcategory(incategory);
    theItem.setproductName(inproductName);
    theItem.setItemNumber(mNextItemNumber++);
    theItem.add();

    return theItem;
  }
  Item& Database::getItem(int inItemNumber)
  {
    for (int i = 0; i < mNextSlot; i++) {
      if (mItems[i].getItemNumber() == inItemNumber) {
	return mItems[i];
      }
    }

    cerr << "No item with that item number " << inItemNumber << endl;
    throw exception();
  }

  Item& Database::getItem(string incategory, string inproductName)
  {
    for (int i = 0; i < mNextSlot; i++) {
      if (mItems[i].getcategory() == incategory &&
	  mItems[i].getproductName() == inproductName) {
	return mItems[i];
      }
    }

    cerr << "No match with item name " << incategory << " " << inproductName << endl;
    throw exception();
  }
  void Database::displayAll()
  {
    for (int i = 0; i < mNextSlot; i++) {
      mItems[i].display();
    }
  }

  void Database::displayCurrent() // List current items
  {
    for (int i = 0; i < mNextSlot; i++) {
      if (mItems[i].getIsAdded()) {
	mItems[i].display();
      }
    }
  }

  void Database::displayCancelled() // List cancelled items
  {
    for (int i = 0; i < mNextSlot; i++) {
      if (!mItems[i].getIsAdded()) {
	mItems[i].display();
      }
    }
  }
}
