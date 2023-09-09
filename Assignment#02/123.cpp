#include <iostream>
#include <fstream>
using namespace std;

struct Node {
	int ID;
	Node* next;
	Node* previous;
};
int c1 = 0;
int mid1 = 0;
int mid2 = 0;
Node* start = nullptr;
Node* temp = (Node*)malloc(sizeof(struct Node));


void ADD(int b) {
	Node* temp = (Node*)malloc(sizeof(struct Node));
	cout << "ok" << endl;
	temp->ID = b;
	temp->next = nullptr;
	if (start == nullptr) {
		start = temp;
		start->previous = nullptr;
		mid1 = start->ID;
		c1 = 1;
	}
	else {
		struct Node* current = start;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = temp;
		temp->previous = current;
	    
		if (c1 == 0) {                     // when it is odd
			mid1 = mid2;
			c1 = 1;
		}
		else {                             //when it is even
			struct Node* current = start;
			while (mid1 != current->ID) {
				current = current->next;
			}
			current = current->next;
			mid2 = current->ID;
			c1 = 0;
		}
	}
}
void Delete() {
	Node* current = start;
	while (current->next != nullptr) {
		current = current->next;
	}
	if (current->ID == start->ID) {
		start = start->next;
		free(current);
		cout << "start deleted" << endl;
	}
	else {
		Node* prev = start;
		Node* curr = start->next;
		while (curr->next != nullptr) {
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
		free(curr);
		cout << "deleted the last value" << endl;
		if (c1 == 0) {                           //when it is odd
			c1 = 1;
		}
		else {                                   //when it is even
			Node* curr = start;
			while (curr->ID != mid1) {
				curr = curr->next;
			}
			curr = curr->previous;
			int temp = mid1;
			mid1 = curr->ID;
			mid2 = temp;
			c1 = 0;

		}
	}
}

void GetTrump() {
	if (c1 == 0) {
		cout << "middle numbers are " << mid1 << " and " << mid2 << endl;
	}
	else {
		cout << "middle number is: " << mid1 << endl;
	}
}

int main() {
	int number;
	string operation = "z";
	ifstream storefile("c:/Users/Faisal Khan/Desktop/Q1.txt");
	operation = storefile.get();

	while (operation != "E") {
		if (operation == "A") {
			storefile.seekg(3, ios::cur);
			storefile >> number;
			ADD(number);
		}
		if (operation == "D") {
			Delete();
			storefile.seekg(6, ios::cur);
		}
		operation = storefile.get();
		cout << operation << endl;
	}
	GetTrump();

}