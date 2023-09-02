#include <iostream>
using namespace std;
//METHOD#01:

/*

int search (int arr[],int size,int key){
    for(int i = 0;i<size;i++){
        if(arr[i]==key){
            key = arr[i];
            cout << "the value of key is:" << arr[i]<<" at index: "<< i;
            break;
        }
                
    }
    return key;

}

int main(){
    int arr[7] = {2,13,65,98,101,-2,12};
    int key;
    cout << "enter the value search for: ";
    cin >> key;
    int size = 7;
    search(arr,size,key);


    return 0;
}

*/

bool search(int arr[], int size ,int key){
    for (int i = 0; i<size ;i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}

int main(){
    int arr [5]= {1,23,54,24,75};
    int key,size=5;
    cout<<"enter value search for:";
    cin>>key;
    bool found = search(arr,size,key);
    if(found == 1){
        cout<<"key is present.";
    }
    else{
        cout<<"key is not present.";
    }


    return 0;

}