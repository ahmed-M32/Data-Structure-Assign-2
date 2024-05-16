#include "Heap.h"

Heap::Heap(vector<Item> arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        heap.push_back(arr[i]);
    }
}

void Heap::insert_item(Item item)
{
    heap.push_back(item);
}

void Heap::Delete_item(int index)
{
    heap.erase(heap.begin() + index - 1);
}

int Heap::Get_parent(int num)
{
    return (num - 1) / 2;
}

int Heap::Get_Left_Chlid(int num)
{
    return (num * 2) + 1;
}

int Heap::Get_Right_Child(int num)
{
    return (num * 2) + 2;
}

void Heap::Insert_Item(Item item)
{
    heap.push_back(item);
}

void Heap::Heap_sort()
{
    int n = heap.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Max_heapify(n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        Max_heapify(i, 0);
    }
}

void Heap::Heap_sort_Name()
{
    int n = heap.size();

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Max_heapify_By_Name(n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        Max_heapify_By_Name(i, 0);
    }
}

void Heap::Max_heapify(int size, int i)
{
    int left = Get_Left_Chlid(i);
    int right = Get_Right_Child(i);
    int Max = i;

    if (heap[Max] < heap[left] and left < size)
    {
        Max = left;
    }
    if (heap[Max] < heap[right] and right < size)
    {
        Max = right;
    }

    if (Max != i)
    {
        swap(heap[i], heap[Max]);
        Max_heapify(size, Max);
    }
}

void Heap::Min_heapify(int i)
{

    if (i > heap.size())
    {
        return;
    }
    int left = Get_Left_Chlid(i);
    int right = Get_Right_Child(i);
    int Min = i;

    if (heap[Min] >= heap[left] and left < heap.size())
    {
        Min = left;
    }
    if (heap[Min] >= heap[right] and right < heap.size())
    {
        Min = right;
    }

    if (Min != i)
    {
        swap(heap[i], heap[Min]);
        Min_heapify(Min);
    }
}

void Heap::Build_Max()
{
    for (int i = (heap.size() / 2 - 1); i >= 0; i--)
    {
        Max_heapify(heap.size(), i);
    }
}

void Heap::Build_Min()
{
    for (int i = ((heap.size() / 2) - 1); i >= 0; i--)
    {
        Min_heapify(i);
    }
}

void Heap::Max_heapify_By_Name(int size, int i)
{

    int left = 2*i+1;
    int right = 2*i+2;
    int Max = i;
    if ((heap[Max] < heap[left].itemName) and left <= size)
    {
        Max = left;
    }
    if ((heap[Max] < heap[right].itemName) and right <= size)
    {
        Max = right;
    }
    if (Max != i)
    {
        swap(heap[i], heap[Max]);
        Max_heapify_By_Name(size, Max);
    }
}

void Heap::Min_heapify_By_Name(int i)
{

    int left = Get_Left_Chlid(i);
    int right = Get_Right_Child(i);
    int Min = i;

    if (heap[Min] > heap[left].itemName and left < heap.size())
    {
        Min = left;
    }
    if (heap[Min] > heap[right].itemName and right < heap.size())
    {
        Min = right;
    }

    if (Min != i)
    {
        swap(heap[i], heap[Min]);
        Min_heapify_By_Name(Min);
    }
}

void Heap::Build_Max_By_Name()
{
    int n = heap.size();
    for (int i = floor(n / 2) - 1; i >= 0; i--)
    {
        cout << i << endl;
        Max_heapify_By_Name(n, i);
    }
}

void Heap::Build_Min_By_Name()
{
    for (int i = ((heap.size() / 2) - 1); i >= 0; i--)
    {
        cout << i << endl;
        Min_heapify_By_Name(i);
    }
}

void Heap::print_heap()
{
    for (int i = 0; i < heap.size(); i++)
    {
        heap[i].print();
    }
}
