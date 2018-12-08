// UserInterface.cpp

#include <iostream>
#include <stdexcept>
#include <string>

#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doAdd(Database& inDB);
void doCancel(Database& inDB);
void doDiscount(Database& inDB);


int main(int argc, char** argv)
{
  Database itemDB;
  bool done = false;

  while (!done) {
    int selection = displayMenu();

    switch (selection) {
    case 1:
      doAdd(itemDB);
      break;
    case 2:
      doCancel(itemDB);
      break;
    case 3:
      doDiscount(itemDB);
      break;
    case 4:
      itemDB.displayAll();
      break;
    case 5:
      itemDB.displayCurrent();
      break;
    case 6:
      itemDB.displayCancelled();
      break;
    case 0:
      done = true;
      break;
    default:
      cerr << "Unknown command." << endl;
    }
  }
}

int displayMenu()
{
  int selection;

  cout << endl;
  cout << "Online Store Database" << endl;
  cout << "-----------------" << endl;
  cout << "1) Order a new item" << endl;
  cout << "2) Cancel an item" << endl;
  cout << "3) Discount an item in percentage" << endl;
  cout << "4) List all items" << endl;
  cout << "5) List all current items" << endl;
  cout << "6) List all cancelled items" << endl;
  cout << "0) Quit" << endl;
  cout << endl;
  cout << "---> ";

  cin >> selection;

  return selection;
}

void doAdd(Database& inDB)
{
  string category;
  string productName;

  cout << " Please enter without any blank space." << "\nCategory?\n";
  cin >> category;
  cout << "Product name?\n";
  cin >> productName;
 
  try {
    inDB.addItem(category, productName);
  } catch (std::exception ex) { 
    cerr << "Unable to add new item!" << endl;
  }
}

void doCancel(Database& inDB)
{
  int ItemNumber;

  cout << "Item number? ";
  cin >> ItemNumber;

  try {
    Item& itm = inDB.getItem(ItemNumber); // Cancel item
    itm.cancel();
    cout << "Item " << ItemNumber << "has been cancelled." << endl;
  } catch (std::exception ex) {
    cerr << "Unable to cancel item!" << endl;
  }
}

void doDiscount(Database& inDB) // Discount item 
{
  int ItemNumber;
  int discountPercent;

  cout << "item number? ";
  cin >> ItemNumber;

  cout << "How much of a discount in percentage? ";
  cin >> discountPercent;

  try {
    Item& itm = inDB.getItem(ItemNumber);
    itm.discount(discountPercent);
  } catch (...) {
    cerr << "Unable to add discount to item!" << endl;
  }
}

