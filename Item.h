#include <bits/stdc++.h>

#ifndef _ITEM
#define _ITEM
using namespace std;
class Item
{
    int Price;

public:
    Item(string name, string category, int price);
    string itemName;
    string Category;


    string get_category();
    bool operator<(Item &another);
    bool operator>(Item &another);
    bool operator<(string &another);
    bool operator>(string &another);
    void print();
    bool operator==(Item &another);
};

#endif
