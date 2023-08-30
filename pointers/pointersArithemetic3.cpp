#include <iostream>
using namespace std;

int main(){

    int arr[2]= {3,8};
    int *ptr = &arr[0];
    
    
    //CASE#01:

    // cout <<ptr<<endl;
    // cout << ++ptr<<endl;
    // cout << *ptr;

    //        OR

    cout << *++ptr << endl;

    //CASE#02:

    cout<< ++*ptr<<endl;//agr case 1 chalega to 9 ans qk ptr me abhi 2nd element ka address h
                        //agr case one run nh krenge to ptr me o index par mojood value ka address h to us value me 1 add ho jayega


    cout << arr[0]<<"   "<<arr[1]; //array has been updated
    return 0;

}