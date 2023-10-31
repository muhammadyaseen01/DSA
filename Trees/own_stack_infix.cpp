#include <iostream>
using namespace std;

struct Stack
{
    char id;
    Stack *next;
};
Stack *head = NULL;
int currSize = 0;

bool isEmpty()
{
    return head == NULL;
}

void push(char new_id)
{
    // overflow ki condition
    Stack *new_node = new Stack();
    new_node->id = new_id;
    new_node->next = head;
    head = new_node;
    currSize++;
}

int pop()
{
    Stack *curr;
    if (head == NULL)
    {
        cout << "Underflow!" << endl;
    }
    else
    {
        cout<<head->id - '0';
        curr = head;
        head = head->next;
        curr->next = NULL; // disconnecting top from the list
        free (curr);
        currSize--;
    }
    
}

int getTop()
{
    if (head == NULL)
    {
        cout << "underflow\n";
        // return 1;
        // return INT_MIN;
    }
    return head->id;
}

int main()
{

    push('a');
    push('b');
    push('c');
    push('d');
    push('e');
    cout << getTop() << endl; // print 5
    cout << "size: " << currSize << endl;
    pop();
    pop();
    cout << getTop() << endl; // print 3
    cout << "size: " << currSize << endl;

    return 0;
}