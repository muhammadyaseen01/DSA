#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int L_child(int i)
{ // node k left child ka index return
    return (2 * i + 1);
}
int R_child(int i)
{ // node k right child ka index return
    return (2 * i + 2);
}
int parent(int i)
{ // node k parent ka index return
    return ((i - 1) / 2);
}

int insert(int *arr , int new_val , int capacity , int size) 
{ // value to be insert
    if (size == capacity) 
        return 0;
    size ++;
    arr[size-1] = new_val;
    for(int i = (size-1) ;i != 0 && arr[parent(i)] > arr[i];){ // i!=0--> i root node ko point nh kr rha AND child parent se less h to swap hoga wrna nh
        swap (arr[i],arr[parent(i)]);
        i = parent(i); // it return index of parent node --> phr me usse check krnga wo sahi jaga h ya nh
    }
    return size;//size ko update krna h baar baar is liye size return krna zarori or inki size me store krnga main me agr aisa nh krge to size update srf function me hoga function k bahar value same rahegi (ya phr argument me size ka address pas kr k bhi kia ja sakta h phr return krne ki zarorat nh)
}

void print(int *arr,int size)
    {
        for(int i=0; i<size; i++)
        {
            cout<<arr[i]<<" ";
        }
    }

int main()
{
    int capacity,n,new_val,size = 0;
    cout << "Define the capacity of array: ";
    cin >> capacity;
    int *arr = new int[capacity];
    cout<< "enter how many number you want to insert: ";
    cin>>n;
    for(int i = 0 ; i<n ; i++){
        cout<<"enter the value you want to insert: ";
        cin>>new_val;
        size = insert(arr,new_val,capacity,size); // size me store is liye qk size return kr rha function to yahan update
    }

    print (arr,size);
    return 0;
}

