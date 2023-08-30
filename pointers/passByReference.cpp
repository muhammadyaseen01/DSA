#include <iostream>
using namespace std;

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int x = 10, y =20;
    cout << x << " " << y<<endl;
    int *x_ptr = &x;
    int *y_ptr = &y;
    swap(x_ptr,y_ptr);

    cout << x << " " << y;


    return 0;
}