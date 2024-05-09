#include "Item.h"

Item::Item(string name, string category, int price)
{
    itemName = name;
    this->Category = category;
    this->Price = price;
}

bool Item::operator<(Item &another)
{
    return (this->Price < another.Price);
}
