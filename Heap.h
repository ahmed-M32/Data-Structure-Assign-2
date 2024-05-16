#include "Item.h"
#include <bits/stdc++.h>

#ifndef HEAP_DS_H
#define HEAP_DS_H

class Heap
{
    vector<Item> heap;

public:
    Heap(vector<Item>);
    int Get_parent(int num);
    int Get_Left_Chlid(int num);
    int Get_Right_Child(int num);
    void Insert_Item(Item item);
    void Heap_sort();
    void Max_heapify( int i);
    void Min_heapify(int i);
    void Build_Max();
    void Build_Min();
    void print_heap();
};

#endif
