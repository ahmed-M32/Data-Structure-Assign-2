#include "Item.h"

Item::Item(string name, string category, int price)
{
    itemName = name;
    this->Category = category;
    this->Price = price;
}

string Item::get_category()
{
    return Category;
}

bool Item::operator<(Item &another)
{ // to compare prices
    return (this->Price < another.Price);
}

bool Item::operator>(Item &another)
{ // to compare prices
    return (this->Price > another.Price);
}

/*bool Item::operator<(string &another_category)
{ // to compare categories
    return (this->Category < another_category);
}*/
bool Item::operator<=(Item &another)
{
    return (this->Price <= another.Price);
}

bool Item::operator>=(Item &another)
{
    return (this->Price >= another.Price);
}

bool Item::operator<(string &another_name)
{
    return (this->itemName < another_name);
}
bool Item::operator>(string &another_name)
{
    return (this->itemName > another_name);
}
bool Item::operator<=(string &another_name)
{
    return (this->itemName <= another_name);
}
bool Item::operator>=(string &another_name)
{
    return (this->itemName >= another_name);
}

/*bool Item::operator<(string &another_category)
{ // to compare categories
    return (this->Category < another_category);
}*/
/*
bool Item::operator>(string &another_category)
{ // to compare categories
    return (this->Category > another_category);
}*/

bool Item::operator==(Item &another)
{
    return (this->Price == another.Price && this->Category == another.Category && this->itemName == another.itemName);
}

void Item::print()
{
    cout << "Item Name: " << itemName << ", Category: " << Category << ", Price: " << Price << endl;
}
