#include <iostream>
#include <queue>
using namespace std;

struct Vertex { // for main list
	char vertex;
	Vertex* next;
	struct Edge* E_head; 
};
Vertex* V_head = NULL;

struct Edge {  // for sub-list
	Vertex* tovertex;
	Edge* next;
};

void InsertVertex(char b) {
	Vertex* new_node = new Vertex;
	new_node->vertex = b;
	new_node->next = NULL;
	new_node->E_head = NULL;
	if (V_head == NULL) {
		V_head = new_node;
	}
	else {
		struct Vertex* current = V_head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
	}
}

void InsertEdge(char b) {
	Vertex* curr = V_head;
	while (curr != NULL) {
		if (curr->vertex == b) {
			cout << "vertex found" << endl;
			break;
		}
		curr = curr->next;
	}
	if (curr == NULL) {
		cout << "sub vertex not found" << endl;
		return;
	}
	char vertex;
	cout << "Enter the course in which Edge wants to enroll: ";
	cin >> vertex;
	Vertex* current = V_head;
	while (current != NULL) {
		if (current->vertex == vertex) {
			Edge* temp = new Edge;
			temp->tovertex = curr;
			temp->next = NULL;
			
			if (current->E_head == NULL) {
				current->E_head = temp;
				cout << "Edge is successfully enrolled in course" << endl;
				return;
			}
			else {
				struct Edge* curren = current->E_head;
				while (curren->next != NULL) {
					curren = curren->next;
				}
				curren->next = temp;
				cout << "Edge is successfully enrolled in course" << endl;
				return;
			}
		}
		current = current->next;
	}
	if (current == NULL)cout << "invalid Main vertex number" << endl;

}
void PrintVertex() {
	Vertex* ptr = V_head;
	if (ptr == NULL) cout << "empty" << endl;
	while (ptr != NULL) {
		cout << ptr->vertex << endl;
		ptr = ptr->next;
	}
}
void PrintEdge() {
	char vertex;
	cout << "Enter the course number: ";
	cin >> vertex;
	Vertex* current = V_head;
	if (current == NULL) {
		cout << "course does not exist" << endl;
	}
	while (current != NULL) {
		if (current->vertex == vertex) {
			Edge* ptr = current->E_head;
			if (ptr == NULL) {
				cout << "empty" << endl;
				return;
			}
			while (ptr != NULL) {
				cout << ptr->tovertex->vertex << endl;
				ptr = ptr->next;
			}
			return;
		}
		current = current->next;
		if (current == NULL)cout << "course does not exist" << endl;
	}
}

void printgraph() {
	struct Vertex* current = V_head;
	if (current == NULL) {
		cout << "Linked List is empty";
	}
	else {
		while (current != NULL) {
			cout << "Vertex : " << current->vertex << endl;
			struct Edge* ECurr = current->E_head;
			while (ECurr != NULL)
			{
				cout << "Edge: " << (ECurr->tovertex->vertex) << endl;
				ECurr = ECurr->next;
			}

			current = current->next;
		}
	}
}

void DeleteVertex(char b) {// deleting a vertex and its reference(edge) everywhere
	
	//first deleting all reference(edge) of the vertex you want to delete
	Vertex* main = V_head;
	while (main != NULL) {
		if (main->vertex != b) { //to not go in the sub list of the vertex itself
			Edge* sub = main->E_head;//current
			if (sub->tovertex->vertex == b) {//if reference is in the start of sub list
				main->E_head = sub->next;
				free(sub);
				main = main->next;
				continue;
			}
			Edge* sub2 = main->E_head->next;//next
			while (sub2 != NULL) {          //to find reference of the vertex in the sublist
				if (sub2->tovertex->vertex == b) {
					sub->next = sub2->next;
					free(sub2);
					break;


				}
				sub = sub->next;
				sub2 = sub2->next;
			}
		}
		main = main->next;
	}

	//now deleting the vertex along with its sub list
	main = V_head;
	Edge* sub=NULL;
	Edge* sub2;
	if (main->vertex == b) { //if the vertex is at the start
		V_head = main->next;
		sub = main->E_head;
		free(main);
	}
	else {
		Vertex* main2 = V_head->next; //next
		while (main2 != NULL) { // if the vertex is in the middle or end
			if (main2->vertex == b) {
				main->next = main2->next;
				sub = main2->E_head;
				free(main2);
				break;
			}
			main = main->next;
			main2 = main2->next;
		}
	}
	if (sub == NULL) {
		cout << "deleted the vertex" << endl;
		return;
	}

	sub2 = sub;//next
	while (sub != NULL) { // deleting sub list
		sub2 = sub2->next;
		free(sub);
		sub = sub2;
	}
	cout << "deleted the vertex" << endl;
	return;
}

void DeleteEdge(char b) { //deleting an edge from a specific vertex
	char vertex;
	cout << "give course no: ";
	cin >> vertex;
	Vertex* current = V_head;
	while (current != NULL) {
		if (current->vertex == vertex) {  // vertex
			
			Edge* prev = current->E_head;
			if (prev == NULL) {
				cout << "no Edge" << endl;
				return;
			}

			if (prev->tovertex->vertex==b) {
				current->E_head = prev->next;
				free(prev);
				return;
			}
			Edge* curr = current->E_head;
			curr = curr->next;
			while (curr != NULL) {
				if (curr->tovertex->vertex == b) {
					prev->next = curr->next;
					free(curr);
					return;
				}
				prev = prev->next;
				curr = curr->next;
			}
			cout << "Edge not found" << endl;
			return;
		}
		current = current->next;
	}
	cout << "Vertex not found" << endl;
}




int main() {
	int a = 0;
	char c;
	while (a != 20) {
		cout << "1 insert vertex, 2 insert edge, 3 print vertx, 4 print Edge, 5 delete Edge from 1 vertex, 6 delete vertex," << endl;
		cin >> a;
		if (a == 1) {
			cin >> c;
			InsertVertex(c);
		}
		if (a == 2) {
			cout << "Enter edge: ";
			cin >> c;
			InsertEdge(c);
		}
		if (a == 3) {
			PrintVertex();
		}
		if (a == 4) {
			PrintEdge();
		}
		if (a == 5) {
			cout << "Enter edge: ";
			cin >> c;
			DeleteVertex(c);
		}

		if (a == 6) {
			cout << "Enter vertex: ";
			cin >> c;
			DeleteEdge(c);
		}

	}
}