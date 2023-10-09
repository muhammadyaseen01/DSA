#include <iostream>
using namespace std;

int n = 10;

int hash_func(int key)
{
    return key % n; // Returning hash value
}

void insert(int hash_val, int hash_key, int arr[])
{
    int i = 0;
    while (i < n)
    {
        int index = (hash_val + i * i) % n; // Calculate the index using quadratic probing

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

void print(int arr[])
{
    for (int i = 0; i < n; i++)
    {
        cout << "value at index: " << i << " is: " << arr[i] << endl;
    }
}

int main()
{
    cout << "Quadratic probing" << endl;
    int arr[10] = {0};
    int no_of_elements;
    cout << "How many elements do you want to insert? ";
    cin >> no_of_elements;
    for (int i = 0; i < no_of_elements; i++)
    {
        int element;
        cout << "Write the element you want to insert? ";
        cin >> element;

        int hash_val = hash_func(element);

        insert(hash_val, element, arr);
    }
    print(arr);

    return 0;
}
