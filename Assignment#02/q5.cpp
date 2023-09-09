#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};
Node* head =NULL;

void ADD(int new_val){
    Node* new_node = new Node;//memory allocate
    new_node->val = new_val;
    new_node->next = NULL;

    if(head == NULL){
        head = new_node;
        return;
    }
    else{
        Node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void display(){
    if(head == NULL){
        cout<<"list is empty!";
        return;
    }
    Node *curr = head;
    while(curr != NULL){
        cout<<curr->val<<"-->";
        curr = curr->next;
    }
}
void ThirdLastDisplay(){
    if(head == nullptr){
        cout<<-1<<endl;
        return;
    }
    Node* curr = head;
    while(curr->next->next->next == nullptr){
        curr = curr->next;
    }
    cout << curr->val;
}

int main(){

    ADD(1);
    ADD(3);
    ADD(4);
    ADD(5);
    ADD(6);

    // display();
    ThirdLastDisplay();



    return 0;
}