#include "Item.h"
#include <bits/stdc++.h>

#ifndef HEAP_DS_H
#define HEAP_DS_H

class Heap
{

public:
    vector<Item> heap;

    Heap(vector<Item>);
    void insert_item(Item item);
    void Delete_item(int index);
    int Get_parent(int num);
    int Get_Left_Chlid(int num);
    int Get_Right_Child(int num);
    void Insert_Item(Item item);
    void Heap_sort();
    void Heap_sort_Name();
    void Max_heapify(int size, int i);
    void Min_heapify(int i);
    void Build_Max();
    void Build_Min();
    void Min_heapify_By_Name(int i);
    void Build_Max_By_Name();
    void Build_Min_By_Name();
    void print_heap();
    void Max_heapify_By_Name(int size, int i );
   
};

#endif
