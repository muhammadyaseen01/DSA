#include <iostream>
using namespace std;

int size = 50;
int arr[50] = {0};

void insert()
{
    int val = 1;
    for (int ind = 0; ind < size; ind++)
    {
        arr[ind] = val;
        val++;
    }
}

void display()
{
    for (int ind = 0; ind < size; ind++)
    {
        cout << "value at index " << ind << " is: " << arr[ind] << endl;
    }
    return;
}

void search()
{
    int key_val;
    cout << "enter the value search for: ";
    cin >> key_val;

    for (int ind = 0; ind < size; ind++)
    {

        if (arr[ind] == key_val)
        {
            cout << "your key_value: "<<arr[ind]<<" is found at index: " <<ind<<endl;
            cout<<endl;
            return;
        }
    }
}

int main()
{
    int num;
    cout << "1). Press 1 to insert element on list:" << endl;
    cout << "2). Press 2 to search element in list:" << endl;
    cout << "3). Press 3 to display all element of the list:" << endl;

    cin >> num;

    while (num != 0)
    {
        if (num == 1)
        {
            insert();
        }
        if (num == 2)
        {
            search();
        }
        if (num == 3)
        {
            display();
        }
        

        cout << "1). Press 1 to insert element on list:" << endl;
        cout << "2). Press 2 to search element in list:" << endl;
        cout << "3). Press 3 to display all element of the list:" << endl;

        cin >> num;
    }

    // insert();
    // display();
    // search();

    return 0;
}