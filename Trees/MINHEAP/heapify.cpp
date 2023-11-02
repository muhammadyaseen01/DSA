#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int L_child(int index)
{ // node k left child ka index return
    return (2 * index + 1);
}
int R_child(int index)
{ // node k right child ka index return
    return (2 * index + 2);
}
int parent(int index)
{ // node k parent ka index return
    return ((index - 1) / 2);
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

// void swap1(int* a, int* b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

int min_heapify(int *arr , int index , int capacity , int size){
    //smallest me us node ka index jo sabse small h (abhi index me 0 h --> usko right or left se compare krnge jo small ayega usko "smallest" se replace krdnge)
    int left_child = L_child(index), right_child = R_child(index),smallest = index; 
    //teeno me index return ho rha h

    if(left_child < size && arr[left_child] < arr[smallest])
        smallest = left_child;

    if(right_child < size && arr[right_child] < arr[smallest])
        smallest = right_child;
    
    if(smallest != index){ //uper mene smallest = i kiya tha---> lakin agr uper ki koi consition true hui to smallest update ho jayega to usse me swap krnga wrna nh krnga(qk smallest dono child se less h is liye swap nh)
        swap (arr[index], arr[smallest]);
        min_heapify(arr ,smallest ,capacity ,size); // ab index me smallest jayega
        //first time index = 0 tha phr increase hota jayega jo child usse replace krega uski jaga

    }
    return size;
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
    // for(int i = 0 ; i<n ; i++){
    //     cout<<"enter the value you want to insert: ";
    //     cin>>new_val;
    //     size = insert(arr,new_val,capacity,size); // size me store is liye qk size return kr rha function to yahan update
    // }
    int index = 0;
    for(int i = 0 ; i<n ; i++){
        cout<<"enter the value you want to insert: ";
        cin>>new_val;
        arr[i] = new_val;
    }
    print (arr,size);

    min_heapify(arr ,index ,capacity ,size);
    cout<<"after heapify"<< endl;
    cout<<"after heapify"<< endl;
    cout<<"after heapify"<< endl;
    

    print (arr,size);



    return 0;
}

