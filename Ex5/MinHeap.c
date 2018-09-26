#include<stdio.h>
struct MinHeap //Structure with heap array, capacity, size
{
    int arr[100];
    int capacity;
    int heap_size;
}h;

void MinHeapify(int);
void swap(int x, int y);
void insertKey(int k);

int parent(int i) { return (i-1)/2; }
int left(int i) { return (2*i + 1); }
int right(int i) { return (2*i + 2); }

void insertKey(int k) //Insert into heap
{
    if (h.heap_size == h.capacity)
    {
        printf("\nOverflow\n");
        return; 
    }
    (h.heap_size)++;
    int i = h.heap_size - 1;
    h.arr[i] = k;
    while (i != 0 && h.arr[parent(i)] > h.arr[i])
    {
       swap(i, parent(i));
       i = parent(i);
    }
}
void MinHeapify(int i) //Heapify the array
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < h.heap_size && h.arr[l] < h.arr[i])
        smallest = l;
    if (r < h.heap_size && h.arr[r] < h.arr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(i,smallest);
        MinHeapify(smallest);
    }
}
void swap(int x, int y) //Swap elements at two indices of heap
{
    int t = h.arr[x];
    h.arr[x] = h.arr[y];
    h.arr[y] = t;
}
int main() //Sample heap operation
{
    h.heap_size = 0;
    h.capacity = 10;
    insertKey(2);
    insertKey(15);
    insertKey(5);
    insertKey(4);
    insertKey(45);
    printf(“%d\n”, h.arr[0]);
    for(int j = 1; j < h.heap_size; j++) printf("%d ", h.arr[j]);
    printf("\n");
    return 0; 
}
