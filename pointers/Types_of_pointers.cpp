#include <iostream>
using namespace std;


// 1).  WILD POINTER
// int main(){

//     int *ptr;
//     int *p1;
//     cout << ptr<< "  "<<*ptr<<endl;
//     cout << p1<< "  "<<*p1<<endl;

//     return 0;

// }

// 2). NULL POINTER:

// int main(){
//     int *p1 = 0;
//     int *p2 = '\0';
//     int *ptr = NULL;
//     cout << p1 << "  "<< p2<<"  "<<ptr<<endl;
//     int x = 14; //line 21 and 22 likhne se proper work krega qk ptr me ab valid address h jo kisi value ko point kr rha h
//     ptr = &x;
//     cout << ptr <<endl;
//     cout << *ptr <<endl; //give segmentation error
//     //segmentation error terminate tha program and rest of the code will not executed
//     cout << "After Error!"; // will not execute due to segmentation error in above line
//     return 0;
// }


//  3). DANGLING POINTER :

// int main(){

//     {
//         int x = 13;
//         int *ptr = &x;
//         cout <<ptr<<endl;
//     }

//     cout << ptr;
//     return 0;
// }


//  4). VOID POINTER:

int main(){

    int x = 13;
    float y =12.6;

    void *ptr = &y;
    ptr = &x;
    int *p1 = (int *)ptr;
    cout << *p1;


    return 0;
}