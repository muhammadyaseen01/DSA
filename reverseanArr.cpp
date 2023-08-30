#include<iostream>
using namespace std;

void reverseArray(int arr[],int size){
    int start = 0;
    int end = size - 1;
    while (start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
void printArray(int arr[],int size){
    cout<<"{";
    for (int i =0;i<size;i++){
        cout << arr[i] << ", ";
    }
    cout<<"}";
}

int main(){
    int arr [5]={1,2,3,4,5};
    int size = 5;
    reverseArray(arr,size);
    printArray(arr,size);
    return 0;
}