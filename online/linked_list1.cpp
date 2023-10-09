#include<iostream>
using namespace std;

struct Node{
    int id;
    Node *next;
};
Node *start = NULL;

void insertAtStart(int b){
    Node*temp = new Node();
    temp->id = b;
    temp->next = start;
    start = temp;
}

void insertAtEnd(){
    int new_id;
    cout<<"enter the id you want to insert: ";
    cin>>new_id;

    //temp == node to be insert
    Node *temp = new Node();
    temp->id = new_id;
    temp->next = NULL;

    if(start == NULL){
        start = temp;
        return;
    }
    else{
        Node *curr = start;
        while(curr->next != NULL){
            curr = curr->next;
        }//curr->next == NULL
        curr->next = temp;   
    }
    
}

void display()
{
    // Node *curr = new Node(); // memory allocation     //Node* curr = head ------> aisy bhi kr sakte direct
    Node *curr = start;             // inintialize a current pointer which traverse and print dones value one by one

    // Node* curr =head;
    cout << "\n List is: ";
    while (curr != NULL)
    {                                   // jab curr NULL hojaye to break hojayega loop(curr null to agy list khatam --->print k liye value hi nh bachegi)
        cout << curr->id << " --> ";   // new_val ko me uper val me store kr chuka hun to ab val me value h to ussi ko print krnga
        // cout << curr->next << 79" ---> "; // print address of next node
        curr = curr->next;              // curr ko move krne k liye curr k next ko curr me store
    }
    cout << "NULL" << endl; // jab list khatam to NULL print
    cout << endl;
}

int main(){
    insertAtEnd();
    insertAtEnd();
    display();
    insertAtStart(35);
    insertAtStart(69);
    insertAtStart(23);
    // insertAtEnd();
    // insertAtEnd();
    display();
    return 0;
}



Node *insert_node = new Node();
