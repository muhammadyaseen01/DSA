// Q#01: delete alternative node and start from 2nd node

#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};
Node* head = NULL;

void insertAtTail(){

    int new_val;
    Node* new_node = new Node();
    cout << "enter the value of node: ";
    cin>> new_val;
    new_node->val = new_val;

            //OR
    //argument me value lelon or usse node me pass krdn direct;
// EG:
    // Node* new_node = new Node();
    // new_node->val = value;
    if(head==NULL){
        head = new_node;
    }
    else{
        Node* curr = head;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void display(){
    Node* curr = head;
    while(curr!=NULL){
        cout<< curr->val<<" --> ";
        curr = curr->next;
    }
    cout << "NULL"<<endl;
}

void deleteAlternateNode(){
    Node* prev = head;
    while(prev!=NULL && prev->next!=NULL){
        Node* curr = prev->next; //1sy node ka next 2nd ko point kr rha
        prev->next = curr->next; // 2nd ka next means 3rd node ko 1st ka next point kr rha h
        free(curr);//2st ka next 3rd ko point kr rha to me 2nd ko delete kr sakta hon
        prev = prev->next;//prev ko agy barhao dnga
    }
}


int main(){
    insertAtTail();
    insertAtTail();
    insertAtTail();
    insertAtTail();
    insertAtTail(); // 5 node(ODD)
    insertAtTail(); // 6 node (EVEN)
    // odd or even dono no of node dal kr dekh li code sahi run kr rha hai
    display();
    deleteAlternateNode();
    display();

    return 0;
}