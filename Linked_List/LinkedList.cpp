#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int val;
    Node *next;
};
Node *head = NULL; // ise mene globally define kia hua h agr nh krta to main me define kr k call by reference k through access krta

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

// {
//     int new_val, node_index, curr_pos = 0;
//     cout << "enter the index where you want to insert the new node: ";
//     cin >> node_index;
//     cout << "enter the value: ";
//     cin >> new_val;

//     if (node_index == 0)
//     {                   // node_index= 0 means 0th index par node add krni h
//         insertAtHead(); // to iske liye function bana hua h usse call kr dnga
//         return;
//     }
//     Node *curr = head;
//     while (curr_pos != node_index - 1)
//     {                      // for EG: n=5 matlab 5th index par value insert krni h to me apne pointer ko 4th index tk le jaonga(5 se pehle walay pr)
//         curr = curr->next; // curr ptr abhi 4th par h or mujhe 5 par value insert krni h mtlb 4 th k agy walay index par
//         curr_pos++;
//     }
//     Node *new_node = new Node(); // new node ki memory allocate ki
//     new_node->val = new_val;     // new node ki val me input val dali
//     new_node->next = curr->next; // uske next me curr ka next matlab pehle 5th index par jo tha usse new node k next me dal dia takay link
//     // hojayen(new node->next or curr->next same node 5th par jo node thi ussy point kr rhy)
//     curr->next = new_node; // to ab curr k next ko new node ko point krwadnga or function successful ho jayega
// }

void updateAtAnyPosition()
{
    int node_index, new_val, curr_pos = 0;
    cout << "\t 1.enter the node index which value you want to update: ";
    cin >> node_index;
    cout << "\t 1.enter the value you want to update: ";
    cin >> new_val;
    Node *curr = head;
    while (curr_pos != node_index)
    {                      // curr position 0 h 0 se input index tk loop chalega )
        curr = curr->next; // or utni bar curr ptr move krega jab input index or curr_pos equal hojayegi to loop end or curr ptr us wqt input index par hoga
        curr_pos++;        // inc in position
    }
    curr->val = new_val; // jis node ki value update krni thi curr ptr us node pr h to curr k andr jo value h usse new_val se replace
}

void searchID()
{
    int id;
    cout << "\t 1.enter the id search for: ";
    cin >> id;

    Node *curr = head;
    if (curr == 0)
    {
        cout << "list is empty!" << endl;
        cout << endl;
        return;
    }
    while (curr->val != id)
    {
        curr = curr->next;
    }
    cout << "entered id: " << curr->val << " is found in the list." << endl;
    cout << endl;
    return;
}

void deleteAtHead()
{                      // iski proper theory copy me h
    Node *curr = head; // first node pr curr ko bhi point krnge
    head = head->next; // head ko 2nd node par move krnge
    free(curr);        // first node ko free(delete krdnge)
}

void deleteAtTail()
{
    Node *prev = head; // prev ptr delete wali node se pehli wali node ko point krega
    while (prev->next->next != NULL)
    {                      // prev ka next last node or prev k next ka next --> last node ka next hoga(NULL);
        prev = prev->next; // jab tk prev 2nd last node ko point k=nh krega to prev ko agy move krte rahnge
    }
    Node *curr = prev->next; // curr pointer me prev ka next means last node initialize krnge
    prev->next = NULL;       // prev ka next last ko point kr rha abhi to usse NULL krnge
    free(curr);              // curr ---> last node ko free krdnge
}

void deleteAtAnyPosition()
{
    int node_index;
    cout << "\t 1. enter the index of node which you want to delete: ";
    cin >> node_index;
    if (node_index == 0)
    {
        deleteAtHead();
        return;
    }

    int curr_pos = 0;
    Node *prev = head;
    while (curr_pos != node_index - 1)
    {
        prev = prev->next;
        curr_pos++;
    }
    Node *curr = prev->next;
    prev->next = curr->next;
    free(curr);

    // OR

    // Node* curr = prev->next;
    // prev->next = prev->next->next;
    // free(curr);
}

void deleteAll()
{
    while (head != NULL)
    {                      // iski proper theory copy me h
        Node *curr = head; // first node pr curr ko bhi point krnge
        head = head->next; // head ko 2nd node par move krnge
        free(curr);        // first node ko free(delete krdnge)
    }
    cout << "list deleted!" << endl;
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

int main()
{

    int num;
    cout << "1)Press 1 to insert Node in the list: " << endl;
    cout << "2)Press 2 to update Node in the list: " << endl;
    cout << "3)Press 3 to delete Node in the list: " << endl;
    cout << "4)Press 4 to delete all Nodes in the list: " << endl;
    cout << "5)Press 5 to search for Nodes in the list: " << endl;
    cout << "6)Press 6 to display the list: " << endl;
    cout << "7)Press 0 to exit from menu: " << endl;
    cin >> num;
    while (num != 0)
    {
        if (num == 1)
        {
            insertAtAnyPosition();
        }
        else if (num == 2)
        {
            updateAtAnyPosition();
        }
        else if (num == 3)
        {
            deleteAtAnyPosition();
        }
        else if (num == 4)
        {
            deleteAll();
        }
        else if (num == 5)
        {
            searchID();
        }
        else if (num == 6)
        {
            display();
        }

        cout << "1)Press 1 to insert Node in the list: " << endl;
        cout << "2)Press 2 to update Node in the list: " << endl;
        cout << "3)Press 3 to delete Node in the list: " << endl;
        cout << "4)Press 4 to delete all Nodes in the list: " << endl;
        cout << "5)Press 5 to search for Nodes in the list: " << endl;
        cout << "6)Press 6 to display the list: " << endl;
        cout << "7)Press 0 to exit from menu: " << endl;

        cin >> num;
    }

    // searchID();
    // int num, i = 0; // initializing variables
    // cout << "enter the numbers of node you want to add: ";
    // cin >> num; // taking input
    // while (i < num)
    // {                   // runnig loop (user_input - 1) times
    //     insertAtHead(); // calling function
    //     i++;            // increament in i
    // }

    // searchID();

    // deleteAll();
    // display();

    // cout<<"in at any position function "<<endl;
    // insertAtAnyPosition();//calling function

    // cout<<"in at last position function "<<endl;
    // insertAtTail();//calling function
    // display();//calling function

    // cout<<"in at update value function "<<endl;
    // updateAtAnyPosition();//calling function
    // display();//calling function

    // cout<<"in at delete at head function "<<endl;
    // deleteAtHead();//calling function
    // display();//calling function

    // cout<<"in at delete at Tail function "<<endl;
    // deleteAtTail();//calling function
    // display();//calling function

    // cout<<"in at delete at any position function "<<endl;
    // deleteAtAnyPosition();//calling function
    // display();//calling function

    return 0;
}