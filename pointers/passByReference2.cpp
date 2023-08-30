#include<iostream>
using namespace std;

void findIndex(string s, char ch,int *first, int *last){
    for (int i = 0; i < s.size(); i++){
        if (s[i]==ch){
            *first = i;
            break;
        }
    }
    for (int i = s.size()-1; i >= 0; i--){
        if (s[i]==ch){
            *last = i;
            break;
        }
    }
}   

int main(){ 
    string s = "aaaabac";
    char ch = 'a';

    int first = -1;
    int last = -1;

    int *first_ptr = &first;
    int *last_ptr = &last;

    findIndex(s , ch , first_ptr , last_ptr);

    cout << *first_ptr<< " "<<*last_ptr<<endl;
    cout << first << " "<< last;


    return 0;
}