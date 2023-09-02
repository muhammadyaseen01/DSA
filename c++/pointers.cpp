#include <iostream>
using namespace std;

int main(){
    int num =5;
    cout << num << endl;
    cout << "address of num is: " << &num << endl;

    int *ptr = &num;
    cout << ptr <<endl;
    cout << *ptr<<endl;


    double d = 4.13;
    double *p2 = &d;

    cout << p2 <<endl;
    cout << *p2<<endl;

    char ch = 'a';
    char *p3 = &ch;

    cout << p3 <<endl;
    cout << *p3<<endl;

    cout << sizeof(ch)<<endl;
    cout << sizeof(num)<<endl;
    cout << sizeof(d)<<endl;
    cout << sizeof(ptr)<<endl;
    cout << sizeof(p2)<<endl;
    cout << sizeof(p3)<<endl;



    return 0;
}