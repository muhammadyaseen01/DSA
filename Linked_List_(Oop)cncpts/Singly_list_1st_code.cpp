#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

int main(){

    Node *n = new Node(17);
    cout << n->val <<"  "<<n->next;

    return 0;
}