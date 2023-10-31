#include <iostream>
#include <stack>
using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int precedence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
    return 1;
    }
    else
    {
        return -1;
    }
}

string InfixToPostfix(string infix)
{
    stack<char> s;
    string postfix;
    for (int i = 0; i < infix.length(); i++)
    {
        // cout<<"for checking"<< infix[i] <<endl;
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while ((!s.empty()) && (s.top() != '(') )
            {
                char curr = s.top();
                postfix += curr;
                s.pop();
            }
            if (s.top() == '(')
            {
                s.pop();
            }
        }
        else if (isOperator(infix[i]))
        {
            if (s.empty()) //opening bracket par bhi shayad direct push krte hain
            {
                s.push(infix[i]);
            }
            else // !empty
            {
                if (precedence(infix[i]) > precedence(s.top()))
                {
                    s.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(s.top())) && (infix[i] == '^'))
                {
                    s.push(infix[i]);
                }
                else
                {
                    while ((!s.empty()) && (precedence(infix[i]) <= precedence(s.top())))
                    {
                        postfix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }
    //if equation ends and there is some operators in stack
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{

    string infix_exp, postfix_exp;
    cout << "Enter a Infix Expression :" << endl;
    cin >> infix_exp;
    cout << "INFIX EXPRESSION: " << infix_exp << endl;
    postfix_exp = InfixToPostfix(infix_exp);
    cout << endl<< "POSTFIX EXPRESSION: " << postfix_exp;

    return 0;
}