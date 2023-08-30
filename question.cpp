#include <iostream>;
using namespace std;

int main() {


    // QUESTION#01://quey h

    // int a = 2;
    // int b = a+1;
    // if((a=5)==b){
    //     cout<<a;
    // }
    // else{
    //     cout << a+4;
    // }

    // QUESTION#02:/query h

    char input ;
    cout << "enter input: ";
    cin>>input;

    if (input>'a' && input<'z'){
        cout<<"input is small alphabet";
    }
    if (input>'A' && input<'Z'){
        cout<<"input is Capital alphabet";
    }
    if (input>47 && input<58){
        cout<<"input is small alphabet";
    }
    else{
        cout<<"fail";
    }



    return 0;
    
}