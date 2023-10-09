#include <iostream>
using namespace std;

int  n = 10;
// fill_n (arr,10,-1);
int hash_func(int key)
{
    return key % n; // returning hash value
}
void insert(int hash_val, int hash_key,int arr[])
{
    int i = 0;
    while (i < n)
    {
        int index = (hash_val + i) % n; //calculating index using linear probing
        if (arr[index] != 0)
        {
            cout << "Collision at index " << index << endl;
            i++;
        }
        else
        {
            cout << "No Collision" << endl;
            arr[index] = hash_key;
            break;
        }
    }
}

void print(int arr[]){
    for(int i=0 ;i<10 ;i++){
        cout<<"value at index: "<< i<<" is: "<<arr[i]<<endl;
    }
}
int main()
{

    int arr[10] = {0};
    int no_of_elements;
    cout << "how many elements you want to insert? ";
    cin >> no_of_elements;
    for (int i = 0; i < no_of_elements; i++)
    {
        int element;
        cout << "write element you want to insert? ";
        cin >> element;

        int hash_val = hash_func(element);

        insert(hash_val, element,arr);
    }
    print (arr);
    // int a = hash_func(24);
    // cout<<a<<" ";
    return 0;
}