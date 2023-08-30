#include <iostream>
using namespace std;

int main(){
    int x = 10;
    float y =13.7;
    // cout << &x<<endl<<&y;

    int *ptr = &x;
    float *ptrf = &y;

    cout <<"address stored in ptr: "<< ptr<<endl ;
    cout<<endl;
    cout <<"values at address which stored in ptr: "<< *ptr<<endl ;
    cout<<endl;
    cout <<"address stored in ptrf: "<< ptrf<<endl ;
    cout<<endl;
    cout <<"values at address which stored in ptrf: "<< *ptrf<<endl ;
    cout<<endl;
   
   //if i change value of x, but pointer still points at same memory so x has been updated at that memory 
   //and same address gives us updated value
    x = 34;
    cout<<"value of x after update is x= "<< x<<endl;
    cout<<endl;
    cout<<"value of x after update access through pointer/dereference operator is x= "<< *ptr <<endl;
    cout<<endl;


    *ptr = 45;
    cout <<"new value of x updated through ptr: "<< *ptr<<endl;
    cout<<endl;

    int value = *ptr;
    cout << value<<endl;


    return 0;
}