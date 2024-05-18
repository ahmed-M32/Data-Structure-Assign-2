#include <bits/stdc++.h>
#include "AVLTree.h"
//#include "Heap.h"
#include "Item.h"
#include "binaryTree.cpp"
// ONLY INCLUDE .h FILES not .cpp
using namespace std;
void binary();
void avl();

int main()
{
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

    bool first_time = true;
    binarytree tree(Item("remove", "remove",0));
    string want_file;
    cout << "Want to add items through file? y/n\n";
    cin >> want_file;
    if(want_file == "y")
    {
        string filename;
        cout << "filename: ";
        cin >> filename;
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Unable to open file " << filename << "!" << endl;
            return;
        }
        int numItems;
        file >> numItems;
        file.ignore();

        string name, category;
        int price;

        for (int i = 0; i < numItems; ++i) {
            getline(file, name);
            getline(file, category);
            file >> price;
            file.ignore();

            if(first_time)
            {
                tree.data.itemName = name;
                tree.data.Price = price;
                tree.data.Category = category;
                first_time = false;
            }
            else
            {
                Item newItem(name, category, price);
                tree.insert(newItem);
            }

        }
        file.close();
    }
    int choice;
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
    AVLTree tree;
    string want_file;
    cout << "Want to add items through file? y/n\n";
    cin >> want_file;
    if(want_file == "y")
    {
        string filename;
        cout << "filename: ";
        cin >> filename;
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Unable to open file " << filename << "!" << endl;
            return;
        }
        int numItems;
        file >> numItems;
        file.ignore();

        string name, category;
        int price;

        for (int i = 0; i < numItems; ++i) {
            getline(file, name);
            getline(file, category);
            file >> price;
            file.ignore();


            Item newItem(name, category, price);
            tree.insert(newItem);
        }
        file.close();
    }
    int choice;
    bool break_loop = false;
    while (true)
    {
        cout << "1- Add item data\n";
        cout << "2- Remove item data\n";
        cout << "3- Display all the items sorted by their name ascending\n";
        cout << "4- Display all the items sorted by their name descending\n";
        cout << "5- Display all the items sorted by their prices ascending\n";
        cout << "6- Display all the items sorted by their prices descending\n";
        cout << "7-Exit\n";
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
                cout << "Item name:\n";
                cin >> name;
                cout << "Item category: \n";
                cin >> categ;
                cout << "Item price:\n";
                cin >> price;
                tree.pop(Item(name, categ, price));
                break;
            case 3:
                tree.traverse_ascend_name();
                break;
            case 4:
                tree.traverse_descend_name();
                break;
            case 5:
                tree.traverse_ascend_price();
                break;
            case 6:
                tree.traverse_descend_price();
                break;
            case 7:
                break_loop = true;
                break;
        }
        if(break_loop)
            break;
    }
}

