#include <cstdlib>

#include<iostream>

#include<bits/stdc++.h>



using namespace std;



void Minheapify(vector<int> &arr,int size,int i){

    

    int li=((2*i)+1);

    int ri=((2*i)+2);

    int smallest=i;

    if(li<size && arr[li]<arr[smallest])

    smallest=li;

    if(ri<size && arr[ri]<arr[smallest])

    smallest=ri;



    if(smallest !=i ){

        swap(arr[i],arr[smallest]);

        Minheapify(arr,size,smallest);

    }



}

// T.C : O(log size)



int main(){

    

    vector<int> brr={40,20,30,35,25,80,32,100,70,60};

    int a= brr.size();

    for(int i=a/2;i>=0;i--){

        Minheapify(brr,a,i);

    }

    cout<<"After heapifying the arr: ";

    for(auto x: brr){

        cout<<x<<" ";

    }

    

    return 0;

}
