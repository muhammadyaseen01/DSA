#include<iostream>
using namespace std;

int sumArray(int arr[],int n){
    int sum=0;
    
    for (int i = 0;i<n;i++){
        sum = sum + arr[i];
        // cout<<arr[i]<<endl;
    }
    return sum;
}

int main(){
    int size,a;
    cout << "enter size how many element you want to store in an array: ";
    cin>>size;

    int arr [100];

    for (int i = 0; i<size; i++){
        cout << "enter the value at index arr[" << i << "]: ";
        cin>>arr[i];
    }

    a = sumArray(arr,size);
    cout<< a;
    
}