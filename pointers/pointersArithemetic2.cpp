#include <iostream>
using namespace std;

int main(){
    // int arr[2] = {1,19};
    // int *ptr = &arr[0];

    // cout << ptr <<" "<<*ptr<<endl;//address or first element of array and first element of array

    // cout <<*ptr++<<endl;//print value at index ptr but after that it increament the address by (size)--->int=4 bytes etc

    // cout << arr[0] << "   "<< arr[1]<<endl;
    // cout << ptr <<"  " <<*ptr<<endl;//address of 2nd element bcz of increament in ptr(*ptr++) and value at that index printed

    int arr1[3]={7,8,4};
    int *ptr1 = &arr1[0];

    cout << ptr1 <<" "<<*ptr1<<endl;
    cout <<(*ptr1)++<<endl;
    cout << ptr1 <<" "<<*ptr1<<endl;
    


    return 0;
}