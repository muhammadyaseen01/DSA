#include <iostream>
using namespace std;

int main(){

    int x = 15;
    int *ptr = &x;

    double y = 7.6;
    double *ptr_y = &y;
    cout << sizeof(y)<<endl;
    cout << ptr_y<< "  "<<(ptr_y + 1)<<endl;

    cout << "size of x is: "<<sizeof(x)<<endl;
    cout << "size of x is: "<<(sizeof x)<<endl;

    cout << ptr<< "  "<<(ptr + 1);

    return 0;
}