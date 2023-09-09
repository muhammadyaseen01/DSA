#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    Node *prev;
    int val;
    Node *next;
};
Node *head = NULL;
Node *tail = NULL;
int mid1,mid2,counter = 0;


Node *GetFirstMiddle()
{ // return node ho rhi h
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *GetSecondMiddle()
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = slow->prev;
    return slow;
}

void ADD(int new_val)
{
    cout<<"ok";
    
    Node *new_node = new Node;
    new_node->val = new_val;
    new_node->next = NULL;
    new_node->prev = tail;

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
        counter++;
        mid1 = head->val;
        return;
    }

    if (tail != NULL)
    {
        tail->next = new_node;
        new_node->prev = tail;
    }
    tail = new_node;
    counter++;
    if (counter % 2 == 0)
    {
        mid1 = GetFirstMiddle()->val;
        mid2 = GetSecondMiddle()->val;
    }
    else
    {
        mid1 = GetFirstMiddle()->val;
    }
    return;
}

void DELETE()
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *curr = tail;
    tail = tail->prev;

    tail->next = NULL;

    free(curr);
    counter--;
    if (counter % 2 == 0)
    {
        mid1 = GetFirstMiddle()->val;
        mid2 = GetSecondMiddle()->val;
    }
    else
    {
        mid1 = GetFirstMiddle()->val;
    }
    return;
}



void getTrump()
{
    if (counter % 2 == 0)
    {
        cout <<mid1<<endl;
        cout <<mid2<<endl;
    }
    else
    {
        cout <<mid1<<endl;
    }
}

void display()
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->val << "<-->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}



// int main()
// {
//     fstream file;
//     file.open("D:/YASEEN/yaseen/4th semester/DSA/Assignment#02/TestCases/TestCases\01/Test01.txt",ios::out);

//     ADD();
//     ADD();
//     ADD();
//     ADD();
//     ADD();

//     // DELETE();
//     // DELETE();

//     // display();

//     getTrump();

//     return 0;
// }

// ... (rest of your code)

// void testcases(const string &filename)
// {



//     ifstream file(filename);  
//     if (!file)
//     {
//         cout << "Error opening file: " << filename << endl;
//         return;
//     }

//     string testCase = "Y";
//     int read_val;
//     testCase = file.get();

//     while (testCase != "E"){
//         // cout<<"ok";
//         // cout<<testCase;
//         if (testCase == "A")
//         {
//             file.seekg(3, ios::cur);
//             file >> read_val;
//             ADD(read_val);
//         }
//         else if (testCase == "D")
//         {
//             file.seekg(6, ios::cur);
//             DELETE();
//         }
//         testCase = file.get();
//     }

//     file.close();
// }

int main()
{
    // ADD(2);
    // ADD(3);
    // ADD(4);
    // ADD(5);

    // getTrump();


	int number;
	string operation = "z";
	ifstream storefile;
    storefile.open("D:/YASEEN/yaseen/4th semester/DSA/Assignment#02/TestCases/TestCases/01/Test01.txt");
	operation = storefile.get();
    // if(){
    //     cout<<operation;
    // }
    
	while (operation != "E") {

        // cout<<"ok";
		if (operation == "A") {
            cout<< operation;
			storefile.seekg(3, ios::cur);
			storefile >> number;
			ADD(number);
            
		}
		if (operation == "D") {
			DELETE();
			storefile.seekg(6, ios::cur);
		}
		operation = storefile.get();
		cout << operation << endl;
	}
    cout<<"ok";
	getTrump();



    // ifstream file(filename);


    // const string filename = "D:/YASEEN/yaseen/4th semester/DSA/Assignment#02/TestCases/TestCases/01/Test01.txt"; // Replace with your test case file path
    // testcases(filename);

    // getTrump();

    return 0;
}
