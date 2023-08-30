#include <iostream>
using namespace std;

int main(){
    int x,y; //declaring variables.
    cout << "enter the value: ";
    cin>>x; //taking inputs from user
    cout << "enter the value: ";
    cin>>y; //taking inputs from user
    
    int *x_ptr = &x; //initializing pointer and store address of x
    int *y_ptr = &y; //initializing pointer and store address of y

    int result; //declaring variable
    int *result_ptr = &result; //initializing pointer and store address of result

    *result_ptr = *x_ptr + *y_ptr;// valur at x_ptr + value at y_ptr update in result_ptr

    cout <<*result_ptr<<endl;

    cout << result<<endl;

    int final_result = *result_ptr;
    cout << final_result;


    return 0;

}