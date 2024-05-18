#include <bits/stdc++.h>
#include "AVLTree.h"

#include "Heap.h"
#include "Item.h"
#include "binaryTree.cpp"

// ONLY INCLUDE .h FILES not .cpp
using namespace std;
void binary();

void avl();

void readItems(const string &filename, AVLTree &tree, bool by_price = true)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error: Unable to open file " << filename << "!" << endl;
        return;
    }

    int numItems;
    file >> numItems;
    file.ignore();

    string name, category;
    int price;

    for (int i = 0; i < numItems; ++i)
    {
        getline(file, name);
        getline(file, category);
        file >> price;
        file.ignore();

        Item newItem(name, category, price);
        if (by_price)
        {
            tree.insert_by_price(newItem);
        }
        else
        {
            tree.insert_by_name(newItem);
        }
    }

    file.close();
}

int main()
{


    

 
  
    int choice;
    cout << "Choose Data Structure: \n";
    cout << "1- Binary Search Trees\n";
    cout << "2- Heaps\n";
    cout << "3- AVL Trees\n";
    cin >> choice;
    vector<Item> items;

    switch (choice)
    {
    case 1: // Binary search tree
        break;
    case 2: // Heap
        Heap heap();
        break;
    case 3:
        AVLTree tree;
        break;
    }
    bool break_loop = false;
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
        case 1: // add by price
            break;
        case 2: // add by name
            break;
        case 3: // read from file
            break;
        case 4: // remove item
            break;
        case 5: // display sorted by name ascend
            break;
        case 6: // display sorted by name descend
            break;
        case 7: // display sorted by price ascend
            break;
        case 8: // display sorted by name descend
            break;
        case 9: // Break
            break_loop = true;
            break;
        }
        if (break_loop)
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

