#include <iostream>
using namespace std;

int main(){
    int arr[3]={12,7,4};
    int *ptr = &arr[0];

    // cout << ptr <<endl;
    // cout<< arr<<endl; //arr contain the address of oth index of array
    // cout << *arr << endl;
    // cout << *ptr << endl;

    cout << *(arr + 0)<<"   "<< *(arr + 1)<<"   "<<*(arr + 2)<<endl;


    return 0;
}