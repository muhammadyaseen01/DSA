#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};
Node* head = NULL;
struct Block
{
    int val;
    Block *next;
};
Block *head2 = NULL; 

void insertAtHead()
{
    int new_val; // initialize var for input
    cout << "\t 1.enter the value: ";
    cin >> new_val; // taking input

    Node *new_node = new Node; // contruct a pointer which point on new node user want to insert
    new_node->val = new_val;   // storing value of input in new node k next me
    new_node->next = head;     // new node k next ko head(ya jese agar koi node h to uska address new k next me)
    head = new_node;           // new node ko head se replace so new node will become the first node
}

void insertAtTail()
{
    int new_val; // initializing variable
    cout << "\t 1.enter the value: ";
    cin >> new_val; // taking input

    Node *new_node = new Node(); // C lang me malloc use hota h
    new_node->val = new_val;     // storing value of input in new node k next me
    new_node->next = NULL;       // we add this node at end so we store NULL in the next of last node(i.e)new_node->next
    if (head == NULL)
    {                    // if list has no node
        head = new_node; // if there is no node exist then add new_node at head
        // insertAtHead();//    [YE LOGIC PROBLEM KR RHI H SIR SE POCHNA H ISKA].
    }
    else
    {
        Node *curr = head; // curr ptr bna kr usse move karwaynge
        while (curr->next != NULL)
        {                      // jab tak last node na ajaye
            curr = curr->next; // curr ptr ko move kr rhy
        }
        curr->next = new_node; // last node par pohch gya curr to uske next me new_node store krdnge
    }
}

void insertAtAnyPosition()
{
    int n;
    cout << "\t 1.Press 1 to insert node at the Head of list: " << endl;
    cout << "\t 2.Press 2 to insert node at Arbitrary position of list: " << endl;
    cout << "\t 3.Press 3 to insert node at the Tail of list: " << endl;
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
        cout << "\t 1.Enetr the value you want to add in Node: ";
        cin >> new_val;
        cout << "\t 2.Enter the index where you want to insert: ";
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

            new_node->next = curr->next;
            curr->next = new_node;
        }
        else
        {
            cout << "Invalid Position!" << endl;
        }

        return;
    }
}






void insertAtHead_b()
{
    int new_val; // initialize var for input
    cout << "\t 1.enter the value: ";
    cin >> new_val; // taking input

    Block *block_new = new Block; // contruct a pointer which point on new block user want to insert
    block_new->val = new_val;   // storing value of input in new block k next me
    block_new->next = head2;     // new block k next ko head2(ya jese agar koi block h to uska address new k next me)
    head2 = block_new;           // new block ko head2 se replace so new block will become the first block
}

void insertAtTail_b()
{
    int new_val; // initializing variable
    cout << "\t 1.enter the value: ";
    cin >> new_val; // taking input

    Block *block_new = new Block(); // C lang me malloc use hota h
    block_new->val = new_val;     // storing value of input in new block k next me
    block_new->next = NULL;       // we add this block at end so we store NULL in the next of last block(i.e)block_new->next
    if (head2 == NULL)
    {                    // if list has no block
        head2 = block_new; // if there is no block exist then add block_new at head2
        // insertAtHead2();//    [YE LOGIC PROBLEM KR RHI H SIR SE POCHNA H ISKA].
    }
    else
    {
        Block *curr = head2; // curr ptr bna kr usse move karwaynge
        while (curr->next != NULL)
        {                      // jab tak last block na ajaye
            curr = curr->next; // curr ptr ko move kr rhy
        }
        curr->next = block_new; // last block par pohch gya curr to uske next me block_new store krdnge
    }
}

void insertAtAnyPosition_b()
{
    int n;
    cout << "\t 1.Press 1 to insert block at the Head2 of list: " << endl;
    cout << "\t 2.Press 2 to insert block at Arbitrary position of list: " << endl;
    cout << "\t 3.Press 3 to insert block at the Tail of list: " << endl;
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
        int new_val, block_index, curr_pos = 0;
        cout << "\t 1.Enetr the value you want to add in Block: ";
        cin >> new_val;
        cout << "\t 2.Enter the index where you want to insert: ";
        cin >> block_index;

        Block *curr = head2;
        while (curr_pos != block_index - 1)
        {
            curr = curr->next;
            curr_pos++;
        }
        if (curr != NULL)
        {
            Block *block_new = new Block;
            block_new->val = new_val;

            block_new->next = curr->next;
            curr->next = block_new;
        }
        else
        {
            cout << "Invalid Position!" << endl;
        }

        return;
    }
}



void display()
{
    Node *curr = new Node(); // memory allocation     //Node* curr = head ------> aisy bhi kr sakte direct
    curr = head;             // inintialize a current pointer which traverse and print dones value one by one

    // Node* curr =head;
    cout << "\n List is: ";
    while (curr != NULL)
    {                                   // jab curr NULL hojaye to break hojayega loop(curr null to agy list khatam --->print k liye value hi nh bachegi)
        cout << curr->val << " --> ";   // new_val ko me uper val me store kr chuka hun to ab val me value h to ussi ko print krnga
        cout << curr->next << " ---> "; // print address of next node
        curr = curr->next;              // curr ko move krne k liye curr k next ko curr me store
    }
    cout << "NULL" << endl; // jab list khatam to NULL print
    cout << endl;
}

void display_b()
{
    Block *curr = new Block(); // memory allocation     //Node* curr = head2 ------> aisy bhi kr sakte direct
    curr = head2;             // inintialize a current pointer which traverse and print dones value one by one

    // Node* curr =head2;
    cout << "\n List is: ";
    while (curr != NULL)
    {                                   // jab curr NULL hojaye to break hojayega loop(curr null to agy list khatam --->print k liye value hi nh bachegi)
        cout << curr->val << " --> ";   // new_val ko me uper val me store kr chuka hun to ab val me value h to ussi ko print krnga
        cout << curr->next << " ---> "; // print address of next node
        curr = curr->next;              // curr ko move krne k liye curr k next ko curr me store
    }
    cout << "NULL" << endl; // jab list khatam to NULL print
    cout << endl;
}




bool checkListEqual(){
    Node* ptr1 = head;
    Block* ptr2 = head2;
    while(ptr1!=NULL && ptr2!=NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return(ptr1 == NULL && ptr2 ==NULL);
}



int main(){

    insertAtAnyPosition();
    insertAtAnyPosition();
    insertAtAnyPosition();
    insertAtAnyPosition();
    
    cout<<"2nd list:"<<endl;
    
    insertAtAnyPosition_b();
    insertAtAnyPosition_b();
    insertAtAnyPosition_b();
    insertAtAnyPosition_b();


    display();
    display_b();
    cout<<checkListEqual();

    return 0;
}