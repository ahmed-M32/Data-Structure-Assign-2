#include <bits/stdc++.h>
#include "AVLTree.h"
#include "Heap.h"
#include "Item.h"
#include "binaryTree.cpp"
// ONLY INCLUDE .h FILES not .cpp
using namespace std;
void binary();
void avl();

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
      string data_struct;
      switch (choice)
      {
      case 1: // Binary search tree
        binary();
          break;
      case 2: // Heap
          break;
      case 3:
          avl();
          break;
      }

}

void binary()
{
    int choice;
    binarytree tree(Item("remove", "remove",0));
    bool break_loop = false;
    bool first_time = true;
    while (true)
    {
        cout << "1- Add item data\n";
        cout << "2- Read items from file\n";
        cout << "3- Remove item data\n";
        cout << "4- Display all the items sorted by their name ascending\n";
        cout << "5- Display all the items sorted by their name descending\n";
        cout << "6- Display all the items sorted by their prices ascending\n";
        cout << "7- Display all the items sorted by their prices descending\n";
        cout << "8-Exit\n";
        cin >> choice;
        string name;
        string categ;
        int price;
        switch (choice)
        {
            case 1:// add
                cout << "Item name:\n";
                cin >> name;
                cout << "Item category: \n";
                cin >> categ;
                cout << "Item price:\n";
                cin >> price;
                if(first_time)
                {
                    tree.data.itemName = name;
                    tree.data.Price = price;
                    tree.data.Category = categ;
                    first_time = false;
                }
                else
                    tree.insert(Item(name, categ, price));
                break;
            case 2:// read from file
                break;
            case 3:
                cout << "Item name:\n";
                cin >> name;
                cout << "Item category: \n";
                cin >> categ;
                cout << "Item price:\n";
                cin >> price;
                tree.pop(Item(name, categ, price));
                break;
            case 4:
                tree.print_nameascending();
                break;
            case 5:// display sorted by name ascend
                tree.print_namedescending();
                break;
            case 6:// display sorted by name descend
                tree.print_prices_ascending();
                break;
            case 7:// display sorted by price ascend
                tree.print_prices_descending();
                break;
            case 8:// Break
                break_loop = true;
                break;
        }
        if(break_loop)
            break;
    }
}


void avl()
{
    int choice;
    AVLTree tree;
    bool break_loop = false;
    while (true)
    {
        cout << "1- Add item data\n";
        cout << "2- Read items from file\n";
        cout << "3- Remove item data\n";
        cout << "4- Display all the items sorted by their name ascending\n";
        cout << "5- Display all the items sorted by their name descending\n";
        cout << "6- Display all the items sorted by their prices ascending\n";
        cout << "7- Display all the items sorted by their prices descending\n";
        cout << "8-Exit\n";
        cin >> choice;
        string name;
        string categ;
        int price;
        switch (choice)
        {
            case 1:// add
                cout << "Item name:\n";
                cin >> name;
                cout << "Item category: \n";
                cin >> categ;
                cout << "Item price:\n";
                cin >> price;
                tree.insert(Item(name, categ, price));
                break;
            case 2:// read from file
                break;
            case 3:
                cout << "Item name:\n";
                cin >> name;
                cout << "Item category: \n";
                cin >> categ;
                cout << "Item price:\n";
                cin >> price;
                tree.pop(Item(name, categ, price));
                break;
            case 4:
                tree.traverse_ascend_name();
                break;
            case 5:// display sorted by name ascend
                tree.traverse_descend_name();
                break;
            case 6:// display sorted by name descend
                tree.traverse_ascend_price();
                break;
            case 7:// display sorted by price ascend
                tree.traverse_descend_price();
                break;
            case 8:// Break
                break_loop = true;
                break;
        }
        if(break_loop)
            break;
    }
}

