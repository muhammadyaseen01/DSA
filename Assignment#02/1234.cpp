#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int ID;
	Node* next;
	Node* previous;
};
int c1 = 0;
int n = 0;
float median = 0;
Node* start = NULL;
Node* temp = (Node*)malloc(sizeof(struct Node));

void ADD(int b) {
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->ID = b;
	if (start == NULL) {
        start = temp;
		start->previous = NULL;
		start->next = NULL;
		median = start->ID;
		c1 = 1;
		n = 1;
	}
	else {
		Node* current = start;
		while (current->next != NULL && current->ID < temp->ID) {
			current = current->next;
		}
		if (current == start&& current->ID >= temp->ID) {          // if the value should be added in start
			
				start = temp;
				start->next = current;
				current->previous = start;
			
			/*else {
				Node* CurrentNext = start->next;
				current->next = temp;
				temp->previous = current;
				temp->next = CurrentNext;
				//CurrentNext->previous = temp;
				cout << "b" << endl;
			}*/
		}
        else if (current->next == NULL&& current->ID < temp->ID) {  // if the value should be added in the end
			current->next = temp;
			temp->previous = current;
			temp->next = NULL;
		}
		else {
			Node* Currentprev = current->previous;
			Currentprev->next = temp;
			temp->previous = Currentprev;
			temp->next = current;
			current->previous = temp;
		}
		n = n + 1;
		// storing median
		if (c1 == 0) {                     // when list is odd
			struct Node* current = start;
			for (int c = 1; c != (n + 1) / 2; c++) {
				current = current->next;
			}
			median = current->ID;
			c1 = 1;
		}
		else {                             //when list is even
			Node* current = start;
			for (int c = 1; c != (n/2);c++) {
				current = current->next;
			}
			float hold = current->ID;
				current = current->next;
			median = (hold+current->ID)/2;
			c1 = 0;
		}
	}

}
void print() {
	Node* ptr = start;
	if (ptr == nullptr) cout << "empty" << endl;
	while (ptr != nullptr) {
		cout << ptr->ID << endl;
		ptr = ptr->next;
	}
}

void printreverse() {
	Node* end = start;
	if (end == nullptr) cout << "empty" << endl;
	while (end->next != nullptr) {
		end = end->next;
	}
	while (end != nullptr) {
		cout << end->ID << endl;
		end = end->previous;
	}
}


int main()
{
	int number;
	int check=0;
	ifstream storefile("c:/Users/Faisal Khan/Desktop/Q2.txt");
	while (check != -1) {
		storefile >> number;
		cout << "read" << number<<endl;
		ADD(number);
		cout << "median is: " << median << endl;
		check = storefile.get();
	}
	print();
	cout << endl;
	printreverse();
	
}	