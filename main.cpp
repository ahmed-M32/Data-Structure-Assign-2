#include <bits/stdc++.h>
#include "AVLTree.h"
#include "Heap.h"
#include "Item.h"
#include "AVLTree.cpp"
#include "Heap.cpp"
#include "Item.cpp"

// ONLY INCLUDE .h FILES not .cpp
using namespace std;

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
    Item i1("item1", "food", 123);
    Item i2("item5", "food", 120);
    Item i3("item4", "food", 156);
    Item i4("item6", "food", 1234);
    Item i5("item3", "food", 122);
    Item i6("item2", "food", 111);
    Item i7("item7", "food", 161);
    vector<Item> arr;
    //
    arr.push_back(i1);
    arr.push_back(i2);
    arr.push_back(i3);
    arr.push_back(i4);
    arr.push_back(i5);
    arr.push_back(i6);
    arr.push_back(i7);
    //
    Heap a(arr);
    //
    a.Build_Max_By_Name();
    a.print_heap();
    //
    //
    
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
