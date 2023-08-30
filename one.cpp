#include <iostream>
using namespace std;

int main(){ 
    // std::cout << "Hello World";
    cout << "Hello World \n" << endl;
/*
    int a = 'a'; // int a = 10
    cout << a << endl;

    bool b = "true";
    cout << b << endl;

    char c = 'c';
    cout << c << endl;

    float f = 1.2;
    cout << f << endl;

    double d = 1.2431;
    cout << d << endl;


    int a = 'a';
    cout << a << endl;

    char ch = 99;
    cout << ch << endl;


    char ch1 = 123456;//int 4 byte me store hota h lakin char 1 byte ka h to 4byte me last byte par jo value ani hogi uska char print
    cout << ch1 << endl;// @ O/P arha h means last byte pr 64 ka binary arha 

    unsigned int b = -102;
    cout << b << endl;


    // int s = sizeof(d); //----> in bytes
    // cout << s << endl;
    cout << sizeof(d) << endl;

*/

    // int a = 2/3;
    // float b = 2.0/3;
    // double c = 2.0/3;
    // cout << a << endl;
    // cout << b << endl;
    // cout << c << endl;


    // RELATIONAL OPERATORS:

    int a = 4;
    int b = 7;

    bool first = (a==b);
    cout << first << endl;

    bool second = (a<b);
    cout << second << endl;
    
    bool third = (a>b);
    cout << third << endl;
    
    bool fourth = (a<=b);
    cout << fourth << endl;
    
    bool fifth = (a>=b);
    cout << fifth << endl;
    
    bool sixth = (a!=b);
    cout << sixth << endl;


    // LOGICAL OPERATORS:
    cout << "LOGICAL OPERATORS:" << endl;
    int c = 10;
    cout << !c << endl;

    c = 0;//c value changed
    cout << !c << endl;


    int d = 0;
    cout << !d << endl;

    return 0;
}