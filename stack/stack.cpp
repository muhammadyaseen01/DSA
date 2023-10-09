#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};
Node *head = NULL;
int currSize=0;

bool isEmpty()
{
    return head == NULL;
}

void push(int new_val){
    //overflow ki condition
    Node *new_node = new Node();
    new_node->val = new_val;
    new_node->next = head;
    head = new_node;
    currSize++;
}

int pop(){
    Node *curr = head;
    head = head->next;
    curr->next =NULL;//disconnecting top from the list
    int result = curr->val;
    delete curr;
    currSize--;//new addition (extra)
    return result;
}

int getTop(){
    if(head == NULL){
        cout<<"underflow\n";
        // return 1;
        // return INT_MIN; 
    }
    return head->val;
}

int main()
{

    // cout<<getTop()<<endl;
    push(1);
    push(2);
    push(32);
    push(4);
    push(5);
    cout<<getTop()<<endl;//print 5
    cout<<"size"<<currSize<<endl;
    pop();
    pop();
    cout<<getTop()<<endl;//print 3
    cout<<"size"<<currSize<<endl;

    return 0;
}