#include <iostream>
using namespace std;
int c,d,a = 5, b =2;

int SUB(){
    c = a -b;
    return c;
}
int ADD(){
    d = SUB();
    return d;
}


int main(){
    cout << ADD();
    return 0;
}