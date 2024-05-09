#include <bits/stdc++.h>

#ifndef _ITEM
#define _ITEM
using namespace std;
class Item
{
    string itemName;
    string Category;
    int Price;

public:
    Item(string name, string category, int price);
    bool operator<(Item &another);
};

#endif
