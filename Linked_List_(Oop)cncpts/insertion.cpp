#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    
};
Node* head = NULL; //ise mene globally define kia hua h agr nh krta to main me define kr k call by reference k through access krta

void insertAtHead(){
    int new_val; //initialize var for input
    cout << "enter the value";
    cin>>new_val;//taking input

    Node* new_node = new Node; //contruct a pointer which point on new node user want to insert
    new_node->val = new_val; //storing value of input in new node k next me 
    new_node->next = head; //new node k next ko head(ya jese agar koi node h to uska address new k next me)
    head = new_node; //new node ko head se replace so new node will become the first node

}

void insertAtTail(){
    int new_val; //initializing variable
    cout<<"enter the value: ";
    cin>>new_val; //taking input

    Node* new_node = new Node(); //C lang me malloc use hota h
    new_node->val = new_val;//storing value of input in new node k next me 
    new_node->next = NULL; //we add this node at end so we store NULL in the next of last node(i.e)new_node->next
    if (head == NULL){ //if list has no node
        head = new_node; //if there is no node exist then add new_node at head 
        // insertAtHead();//    [YE LOGIC PROBLEM KR RHI H SIR SE POCHNA H ISKA].
    }
    else{
        Node* curr = head;  //curr ptr bna kr usse move karwaynge
        while(curr->next!=NULL){ // jab tak last node na ajaye
            curr = curr->next;  //curr ptr ko move kr rhy
        }
        curr->next = new_node; //last node par pohch gya curr to uske next me new_node store krdnge
    }
}

void insertAtAnyPosition(){
    int new_val,n,prev=0;
    cout<<"enter the index where you want to insert the new node: ";
    cin>>n;
    cout<<"enter the value: ";
    cin>>new_val;

    if(n==0){ //n = 0 means 0th index par node add krni h
        insertAtHead(); //to iske liye function bana hua h usse call kr dnga
    }
    Node* curr = head;
    while(prev!=n-1){ //for EG: n=5 matlab 5th index par value insert krni h to me apne pointer ko 4th index tk le jaonga(5 se pehle walay pr)
        curr = curr->next; //curr ptr abhi 4th par h or mujhe 5 par value insert krni h mtlb 4 th k agy walay index par
        prev++;
    }
    Node* new_node = new Node(); //new node ki memory allocate ki
    new_node->val = new_val; //new node ki val me input val dali
    new_node->next = curr->next; //uske next me curr ka next matlab pehle 5th index par jo tha usse new node k next me dal dia takay link 
    //hojayen(new node->next or curr->next same node 5th par jo node thi ussy point kr rhy)
    curr->next = new_node; //to ab curr k next ko new node ko point krwadnga or function successful ho jayega

}

void display(){
    Node* curr = head; //inintialize a current pointer which traverse and print dones value one by one
    
    while(curr!=NULL){ //jab curr NULL hojaye to break hojayega loop(curr null to agy list khatam --->print k liye value hi nh bachegi)
        cout << curr->val<<"   ";//new_val ko me uper val me store kr chuka hun to ab val me value h to ussi ko print krnga
        curr=curr->next; //curr ko move krne k liye curr k next ko curr me store
    }
    cout <<"NULL"; //jab list khatam to NULL print
}

int main(){

    int n,i=0; //initializing variables
    cout<< "enter the number of node you want to enter: ";
    cin>> n; //taking input

    while(i<n){ //runnig loop (user_input - 1) times
        insertAtHead();//calling function
        i++; //increament in i 
    }
    insertAtTail(); //calling function
    display();//calling print function

    return 0;
}