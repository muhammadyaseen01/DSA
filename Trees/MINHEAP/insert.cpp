#include<iostream>
#include <string>
#include <cstdlib>
using namespace std;


class MinHeap {
    int *arr;
    int size;
    int capacity;
    public:
    MinHeap(int c)
    {
        arr = new int[c];
        size = 0;
        capacity = c;
    }
    int left(int i) {return arr[2*i +1];}
    int right(int i) {return arr[2*i+2];}
    int parent(int i) {return (i-1)/2;}
    
    
    void print()
    {
        for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    void insert(int x)
    {
        if(size==capacity)
        {
            return;
        }
        
        size++;
        arr[size-1] = x;
        
        int i = size-1;
        while(i != 0 && arr[parent(i)]>arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i =parent(i);
        }
    }
    
    
    
};
    
    


int main()
{
    MinHeap m(5);
    m.insert(1);
    m.insert(3);
    m.insert(2);
    m.insert(4);
    m.insert(6);
    m.insert(8);
   
    m.print();
}