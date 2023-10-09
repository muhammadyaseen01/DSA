#include<iostream>
using namespace std;

process(int *arr,int n){
    for(int i =0;i<n;i++){
        cout<<*(arr+i)<<endl;
    }
}



int main(){
    int arr [3] = {5,7,2};
    process(arr,3); //arr means address pr arr[0]



    return 0; //koi error nh code me
}