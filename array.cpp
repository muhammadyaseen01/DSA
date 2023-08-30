#include<iostream>
using namespace std;

// int main(){
//     int a;
//     int arr[100] = {0};
//     a = arr[5];
//     cout <<"value at index 5 is:" << a;
//     return 0;
// }


/*

int main(){
    // int a,a1;
    // int arr1[1234];
    int arr[10];
    fill_n(arr,100,24);
    // fill_n(arr1,1234,-24);
    // a = arr[5];
    // a1 = arr1[6]; 
    int arrSize = (sizeof(arr)/sizeof(arr[0])); //suppose:{let arr has 100 elements and every element is of 4 byte i.e 4 * 100 = 400}   sizeof arr is 400 and the size of element is 4(bcz of int)  
    cout << arrSize <<endl;
    for (int i = 1; i<= arrSize;i++){
        cout<<arr[i]<<" ";
    }
    // cout <<"value at index 5 is: " << a<<endl;
    // cout <<"value at index 5 is:" << a1;
    return 0;
}
*/


/*
int main(){
    int arr [10];
    fill_n(arr,10,4);
    int arrSize = (sizeof(arr)/sizeof(arr[0]));
    int arrSize = (sizeof(arr)/sizeof(int));
    cout << arrSize<<endl;
    for (int i = 0;i<arrSize;i++){
        cout << arr[i]<< " ";
    }
}
*/

int toPrint(int one[],int size){
    for(int i = 0; i<size;i++){
        cout << one[i] <<" ";
    }
}


int main (){
    // int arr [10];
    // fill_n(arr, 10, 4);
    char two [5] = {'a','b','c','d','e'};
    int arrSize1 = (sizeof(two)/sizeof(char));
    cout<<arrSize1<<endl;
    int one [10] ={1,2,3,4,5,6,7,8,9,10};
    int arrSize = (sizeof(one)/sizeof(int));
    cout<<arrSize<<endl; 
    toPrint(one,10);
}