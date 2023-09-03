#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};
Node* head = NULL;

void insertAtHead(){
    int new_val;
    cout<<"enter the value want to insert:";
    cin>>new_val;

    Node* new_node = new Node;
    new_node->val = new_val;

    if(head == NULL){
        head = new_node;
        new_node->next = head;
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


    return 0;

}