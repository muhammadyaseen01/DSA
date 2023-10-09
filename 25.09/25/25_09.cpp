#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    char popped;
    string expression = "A + B";
    stack<char> Stack;

    for (char c : expression)
    {
        if (c == '+')
        {
            Stack.push('+');

            if (!Stack.empty())
            {
                char popping_Operator = Stack.top();
                // cout<<"okay";
                Stack.pop();
                popped = popping_Operator;
            }
            else
            {
                cout << "Stack is empty!" << endl;
            }
        }
        

        // cout << "okay"<< endl;
    }
    for(char c: expression){
        if(c!='+'){
            cout<<c;
        }
        else{
            continue;
        }
    }
    cout<<" "<<popped;


    return 0;
}
