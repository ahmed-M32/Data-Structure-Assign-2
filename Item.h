#include <bits/stdc++.h>

#ifndef _ITEM
#define _ITEM
using namespace std;
class Item
{

public:
    Item(string name, string category, int price);
    string Category;
    string itemName;
    int Price;

    string get_category();
    bool operator<(Item &another);
    bool operator>(Item &another);
    bool operator<=(Item &another);
    bool operator>=(Item &another);
    bool operator<(string &another);
    bool operator>(string &another);
    void print();
    bool operator==(Item &another);
};

#endif
