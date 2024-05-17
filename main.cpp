#include <bits/stdc++.h>
#include "AVLTree.h"
#include "Heap.h"
#include "Item.h"
// ONLY INCLUDE .h FILES not .cpp
using namespace std;

int main()
{
//    Item i1("item1", "food", 123);
//    Item i2("item5", "food", 120);
//    Item i3("item4", "food", 156);
//    Item i4("item6", "food", 1234);
//    Item i5("item3", "food", 122);
//    Item i6("item2", "food", 111);
//    vector<Item> arr;
//
//    arr.push_back(i1);
//    arr.push_back(i2);
//    arr.push_back(i3);
//    arr.push_back(i4);
//    arr.push_back(i5);
//    arr.push_back(i6);
//
//    Heap a(arr);
//
//    a.Build_Max_By_Name();
//    a.print_heap();
//
//
      int choice;
      cout << "Choose Data Structure: \n";
      cout << "1- Binary Search Trees\n";
      cout << "2- Heaps\n";
      cout << "3- AVL Trees\n";
      cin >> choice;
      switch (choice)
      {
      case 1: // Binary search tree
          break;
      case 2: // Heap
          break;
      case 3:
          AVLTree tree;
          break;
      }
      while (true)
      {
          cout << "1- Add item data, sorted by price\n";
          cout << "2- Add item data, sorted by name\n";
          cout << "3- Read items from file\n";
          cout << "4- Remove item data\n";
          cout << "5- Display all the items sorted by their name ascending\n";
          cout << "6- Display all the items sorted by their name descending\n";
          cout << "7- Display all the items sorted by their prices ascending\n";
          cout << "8- Display all the items sorted by their prices descending\n";
          cout << "9-Exit\n";
          cin >> choice;

          switch (choice)
          {
          case 1:
              break;
          case 2:
              break;
          case 3:
              break;
          case 4:
              break;
          case 5:
              break;
          case 6:
              break;
          case 7:
              break;
          case 8:
              break;
          case 9:
              break;
          }
      }
}


