#include<iostream>
#include<string>
#include<cstdlib>
#include<math.h>
using namespace std;

struct Stack
{
    int val;
    Stack *next;
};
Stack *head = NULL;
int currSize=0;

bool isEmpty()
{
    return head == NULL;
}

void push(int new_val){
    //overflow ki condition
    Stack *new_node = new Stack();
    new_node->val = new_val;
    new_node->next = head;
    head = new_node;
    currSize++;
}

int pop(){
    Stack *curr = head;
    head = head->next;
    curr->next =NULL;//disconnecting top from the list
    int result = curr->val;
    delete curr;
    currSize--;//new addition (extra)
    return result;
}

int getTop(){
    if(head == NULL){
        cout<<"underflow\n";
        // return 1;
        // return INT_MIN; 
    }
    return head->val;
}

int postfix_Evaluation(string s){
    // int length = s.length();
    for (int i = 0; i < s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            push(s[i] - '0'); // s[i] = 3 h to yahan ascii code ayega 51 usme se agr 48(ascii of 0) minus krdn to 3 ajayega int
        }else{ // number hua to if chalega wrna else (for symbols)
            int operand_2 = getTop();
            pop();
            int operand_1 = getTop();
            pop();
            switch (s[i]){
                case '+':
                    push(operand_1 + operand_2);
                    break;
                case '-':
                    push(operand_1 - operand_2);
                    break;
                case '*':
                    push(operand_1 * operand_2);
                    break;
                case '/':
                    push(operand_1 / operand_2);
                    break;
                case '^':
                    push(pow(operand_1,operand_2));
                    break;
            }
        }

    }
    return getTop(); // ans ko me push kr rha tha stack me to abhi stack k top pr ans hoga to usse get krlnge
}


int main()
{
    // string n = "hello";
    // cout<<n.length();

    cout<<"Answer of the given expression is: "<<postfix_Evaluation("46+2/5*7+");
    return 0;
}