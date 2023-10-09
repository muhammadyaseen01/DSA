#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
};

class stack{
    Node* head;
    int capacity;
    int curr_size;
    public:
    stack(c){
        head = NULL;
        this->capacity = c;
        this->curr_size = 0;
    }

    bool is_empty(){
        return this->head == NULL;
    }  
    
};

int main(){



    return 0;
}