#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int val;
    Node *next;
};
Node *head = NULL;
Node *tail = NULL;

//----------------------------INSERTION-START-------------------------------//

void insertAtHead()
{
    int new_val;
    cout << "enter the value to be insert in the node: ";
    cin >> new_val;

    Node *new_node = new Node;
    new_node->val = new_val;
    new_node->next = head;
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        return;
    }

    if (head != NULL)
    {
        head->prev = new_node;
    }
    head = new_node;
    return;
    // new_node->prev = NULL;
    // cout<<"node inserted"<<endl;
}

void insertAtTail()
{

    if (head == NULL)
    {
        insertAtHead();
        return;
    }

    int new_val;
    cout << "2) enter the value to be insert in the node: ";
    cin >> new_val;

    Node *new_node = new Node;
    new_node->val = new_val;
    new_node->next = NULL;
    new_node->prev = tail;

    if (tail != NULL)
    {
        tail->next = new_node;
        new_node->prev = tail;
    }
    tail = new_node;
    return;
}

void insertAtAnyPosition()
{
    int n;
    cout << "Press 1 to insert node at the Head of list:" << endl;
    cout << "Press 2 to insert node at Arbitrary position of list:" << endl;
    cout << "Press 3 to insert node at the Tail of list:" << endl;
    cin >> n;

    if (n == 1)
    {
        insertAtHead();
        return;
    }

    if (n == 3)
    {
        insertAtTail();
        return;
    }

    if (n == 2)
    {
        int new_val, node_index, curr_pos = 0;
        cout << "Enetr the value you want to add in Node: ";
        cin >> new_val;
        cout << "Enter the index where you want to insert: ";
        cin >> node_index;

        Node *curr = head;
        while (curr_pos != node_index - 1)
        {
            curr = curr->next;
            curr_pos++;
        }
        if (curr != NULL)
        {
            Node *new_node = new Node;
            new_node->val = new_val;

            // for next ptr
            new_node->next = curr->next;
            curr->next = new_node;

            // for prev ptr
            new_node->next->prev = new_node;
            new_node->prev = curr;
        }
        else
        {
            cout << "Invalid Position!" << endl;
        }

        return;
    }
}

//----------------------------INSERTION-END-------------------------------//

//----------------------------DELETION-START-------------------------------//

void deleteATHead()
{
    if (head == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    Node *curr = head;
    head = head->next;
    if(head == NULL){
        tail = NULL;
    }else{
        head->prev = NULL;
    }
    free(curr);
    return;
}

void deleteAtTail(){
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* curr = tail;
    tail = tail->prev;

    tail->next = NULL;

    free(curr);
    return;
}


void deleteAtAnyPosition(){
    int node_index;
    cout<<"Enter the index of node to be delete: ";
    cin>> node_index;

    if(node_index == 0){
        deleteATHead();
        return;

    }
    // else if(node_index == *tail){
    //     deleteAtTail();
    //     return;
    // }
    int curr_pos = 0;
    Node* curr = head;
    while(curr_pos != node_index){
        curr = curr->next; //prev at node_index 
        curr_pos++;
    }
    
    //curr us node ko point kr rha h jo delete krni h
    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;
    free(curr);
    return;
}


void display()
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->val << "<-->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

// GPT wala display:
//  void display()
//  {
//      Node *curr = head;
//      while (curr != NULL)
//      {
//          cout << curr->val;
//          if (curr->next != NULL)
//              cout << "<-->";
//          curr = curr->next;
//      }
//      cout << "NULL" << endl;
//  }

int main()
{
    // insertAtHead();
    // insertAtHead();
    // display();

    // insertAtTail();
    // display();
    // insertAtTail();
    // display();
    // insertAtTail();
    // display();
    // insertAtTail();
    // display();

    insertAtAnyPosition();
    display();
    insertAtAnyPosition();
    display();
    insertAtAnyPosition();
    display();
    insertAtAnyPosition();
    display();

    deleteAtTail();
    display();
    deleteAtAnyPosition();
    display();

    return 0;
}