#include <iostream>
using namespace std;

struct HT_Node
{
    int val = 0;
    HT_Node *next = NULL;
};

int hash_func(int key, int n)
{
    return key % n; // Returning hash value
}

void insert(int hash_val, int hash_key,int arr, int n)//hash_val, element, arr , n
{
    int i = 0;
    while (i < n)
    {
        int index = (hash_val + i) % n; // Calculate the index using quadratic probing

        if (arr[index] != 0)
        {
            cout << "Collision at index " << index << endl;
            HT_Node new_node = new HT_Node;
            new_node->val=hash_key;//Insert the data into node
            new_node->next = NULL;
            HT_Node curr = arr[index];
            while (i < n)
            {
                // if (arr[index]->next == NULL)
                if (curr->next == NULL)
                {
                    // arr[index]->next = new_node;
                    curr->next = new_node;
                    break;
                }
                else
                {
                    curr = curr->next;
                }
            }
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
        if (arr[i]->val == 0)
        {
            cout << "Array is NULL" << endl;
            break;
        }
        else if (arr[i]->next == 0)
        {
            cout << "value at index: " << i << " is: " << arr[i] << endl;
        }
        if (arr[i]->next != 0)
        {
            HT_Node curr = arr[i];
            while (curr->next != 0)
            {
                cout << "value at index: " << i << " is: " << curr->val << endl;
                curr = curr->next;
            }
        }
    }
}

int main()
{
    cout << "open chaining" << endl;
    int n = 10; // size
    HT_Node arr[10];
    int no_of_elements;
    cout << "How many elements do you want to insert? ";
    cin >> no_of_elements;
    for (int i = 0; i < no_of_elements; i++)
    {
        int element;
        cout << "Write the element you want to insert? ";
        cin >> element;

        int hash_val = hash_func(element,n);

        insert(hash_val, element, arr , n);
    }
    print(arr);




    // int n = 10; // size
    // HT_Node arr[10];
    // int hash_val = hash_func(element, n);

    return 0;
}