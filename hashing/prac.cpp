#include <iostream>
using namespace std;

struct HT_Node
{
    int val;
    HT_Node* next;
    HT_Node() : val(0), next(nullptr) {}
};

int hash_func(int key, int n)
{
    return key % n; // Returning hash value
}

void insert(int hash_val, int hash_key, HT_Node arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        int index = (hash_val + i) % n; // Calculate the index using quadratic probing

        if (arr[index].val != 0)
        {
            cout << "Collision at index " << index << endl;
            HT_Node* new_node = new HT_Node;
            new_node->val = hash_key; // Insert the data into node
            new_node->next = nullptr;
            HT_Node* curr = &arr[index];
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = new_node;
            break;
        }
        else
        {
            cout << "No Collision" << endl;
            arr[index].val = hash_key;
            break;
        }
        i++;
    }
}

void print(HT_Node arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].val == 0)
        {
            cout << "Array is NULL" << endl;
        }
        else
        {
            HT_Node* curr = &arr[i];
            if(curr == NULL){
                cout << "value at index: " << i << " is: " << curr->val<<endl;
                curr = curr->next;
            }
            while (curr != NULL)
            {
                cout<<"->"<<curr->val;
                cout << "value at index: " << i << " is: " << curr->val << endl;
                curr = curr->next;
            }
            cout<<endl;
            // cout<<"->NULL"<<endl;
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

        int hash_val = hash_func(element, n);

        insert(hash_val, element, arr, n);
    }
    print(arr, n);

    return 0;
}
