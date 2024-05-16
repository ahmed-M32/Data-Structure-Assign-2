#include <bits/stdc++.h>
#include "AVLTree.h"
#include "Heap.h"
#include "AVLTree.cpp"
#include "Heap.cpp"
#include "Item.h"
#include "Item.cpp"
using namespace std;

int main()
{

    
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
        cout << "1- Add item data\n";
        cout << "2- Remove item data\n";
        cout << "3- Display all the items sorted by their name ascending\n";
        cout << "4- Display all the items sorted by their name descending\n";
        cout << "5- Display all the items sorted by their prices ascending\n";
        cout << "6- Display all the items sorted by their prices descendin\n";
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
        }
    }
}
