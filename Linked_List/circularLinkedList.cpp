#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};
Node* head = NULL;

void insertAtHead(){
    int new_val;
    cout<<"enter the value want to insert: ";
    cin>>new_val;

    Node* new_node = new Node;
    new_node->val = new_val;

    if(head == NULL){
        head = new_node;
        new_node->next = head;
                // OR
        // new_node->next = new_node;
        return;
    }
    Node* tail = head;
    while(tail->next != head){
        tail = tail->next;
    }
    //now tail is pointing to the last node
    tail->next = new_node;
    new_node->next = head;
    head = new_node;
}

void insertAtTail(){
    int new_val;
    cout<<"enter the value want to insert:";
    cin>>new_val;

    Node* new_node = new Node;
    new_node->val = new_val;

    if(head == NULL){
        head = new_node;
        new_node->next = head;
                // OR
        // new_node->next = new_node;
        return;
    }

    Node* tail = head;
    while(tail->next != head){
        tail = tail->next;
    }
    //tail pointing to the last node
    tail->next = new_node;
    new_node->next = head;
}

void insertAtAnyPosition(){
    int new_val,node_index,curr_pos=0;
    cout<<"enter the index where you want to insert the new node: ";
    cin>>node_index;
    cout<<"enter the value: ";
    cin>>new_val;

    if(node_index==0){ //node_index= 0 means 0th index par node add krni h
        insertAtHead(); //to iske liye function bana hua h usse call kr dnga
        return;
    }
    Node* curr = head;
    while(curr_pos!=node_index-1){ //for EG: n=5 matlab 5th index par value insert krni h to me apne pointer ko 4th index tk le jaonga(5 se pehle walay pr)
        curr = curr->next; //curr ptr abhi 4th par h or mujhe 5 par value insert krni h mtlb 4 th k agy walay index par
        curr_pos++;
    }
    Node* new_node = new Node(); //new node ki memory allocate ki
    new_node->val = new_val; //new node ki val me input val dali
    new_node->next = curr->next; //uske next me curr ka next matlab pehle 5th index par jo tha usse new node k next me dal dia takay link 
    //hojayen(new node->next or curr->next same node 5th par jo node thi ussy point kr rhy)
    curr->next = new_node; //to ab curr k next ko new node ko point krwadnga or function successful ho jayega

}


void display(){
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* curr = head;

    do { //ek bar to chalega ohr condition check hogi
        cout << curr->val << "-->";
        curr = curr->next;
    } while (curr != head); 
    cout << head->val << endl;


    //-------------POCHNA H MAAM SE----------------//

    // while (curr->next != head && curr != NULL){
    //     cout << curr->val << "-->";
    //     curr = curr->next;
    // }

}



int main(){


    display();
    insertAtHead();
    insertAtHead();
    insertAtHead();
    display();

    insertAtTail();
    display();

    insertAtAnyPosition();
    display();

    return 0;

}