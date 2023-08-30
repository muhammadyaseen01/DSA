#include <iostream>
using namespace std;

int getMax(int arr[],int n){ //INT_MIN = 2^-31  and INT_MAX=2^31
    int max = INT8_MIN;

    for (int i = 0;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int getMin(int arr[],int n){ //INT_MIN = 2^-31  and INT_MAX=2^31
    int min = INT8_MAX;

    for (int i = 0;i<n;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}


int main(){
    int size;
    cout <<"enter size: ";
    cin>>size;
    int arr[100];
    for(int i = 0;i<size;i++){
        cout << "enter value of arr["<< i << "]: ";
        cin>>arr[i];
    }
    
    cout << "maximum value in array is: " << getMax(arr,size)<<endl;
    cout << "manimum value in array is: " << getMin(arr,size);
    
}