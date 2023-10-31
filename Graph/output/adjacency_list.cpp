#include <iostream>
#include <queue>
using namespace std;

struct Vertex
{ // for main list
    char main_val;
    Vertex *next;
    struct Edge *E_head;
};
Vertex *V_head = NULL;

struct Edge
{ // for sub-list
    Vertex *sub_vertex;
    Edge *next;
};

void InsertVertex(char new_val)
{
    Vertex *new_node = new Vertex;
    new_node->main_val = new_val;
    new_node->next = NULL;
    new_node->E_head = NULL;
    if (V_head == NULL)
    {
        V_head = new_node;
    }
    else
    {
        Vertex *V_curr = V_head;
        while (V_curr->next != NULL)
        {
            V_curr = V_curr->next;
        }
        V_curr->next = new_node;
    }
}
void InsertEdge(char b) {
	Vertex* V_curr = V_head;
	while (V_curr != NULL) {
		if (V_curr->main_val == b) {
			cout << "vertex found" << endl;
			break;
		}
		V_curr = V_curr->next;
	}
	if (V_curr == NULL) {
		cout << "sub vertex not found" << endl;
		return;
	}
	char vertex;
	cout << "Enter the course in which Edge wants to enroll: ";
	cin >> vertex;
    //v_vurr ko hi re initialize kia tha to masla arha tha
	Vertex* current = V_head;
	while (current != NULL) {
		if (current->main_val == vertex) {
			Edge* temp = new Edge;
			temp->sub_vertex = V_curr;
			temp->next = NULL;

			if (current->E_head == NULL) {
				current->E_head = temp;
				cout << "Edge is successfully enrolled in course" << endl;
				return;
			}
			else {
				Edge* curr = current->E_head;
				while (curr->next != NULL) {
					curr = curr->next;
				}
				curr->next = temp;
				cout << "Edge is successfully enrolled in course" << endl;
				return;
			}
		}
		current = current->next;
	}
	if (current == NULL)cout << "invalid Main vertex number" << endl;

}


void PrintVertex()
{
    Vertex *V_curr = V_head;
    if (V_curr == NULL)
    {
        cout << "empty" << endl;
    }
    while (V_curr != NULL)
    {
        cout << V_curr->main_val << endl;
        V_curr = V_curr->next;
    }
}
void PrintEdge() // for printing all Vertex's Edges
{
    char vertex;
    cout << "Enter the Vertex: ";
    cin >> vertex;
    Vertex *V_curr = V_head;
    if (V_curr == NULL)
    {
        cout << "Vertex does not exist" << endl;
    }
    while (V_curr != NULL)
    {
        if (V_curr->main_val == vertex)
        {
            Edge *E_curr = V_curr->E_head;
            if (E_curr == NULL)
            {
                cout << "Empty" << endl;
                return;
            }
            while (E_curr != NULL)
            {
                cout << E_curr->sub_vertex->main_val << endl;
                E_curr = E_curr->next;
            }
            return;
        }
        V_curr = V_curr->next;
        if (V_curr == NULL)
        {
            cout << "Vertex does not exist" << endl;
        }
    }
}

void printgraph()
{
    Vertex *curr = V_head;
    if (curr == NULL)
    {
        cout << "Linked List is empty";
    }
    else
    {
        while (curr != NULL)
        {
            cout << "Vertex : " << curr->main_val << endl;
            // cout << "Vertex : " << curr->main_val << "=>";
            Edge *E_curr = curr->E_head;
            while (E_curr != NULL)
            {
                cout << "Edge: " << E_curr->sub_vertex->main_val << endl;
                // cout << E_curr->sub_vertex->main_val << "->";
                E_curr = E_curr->next;
            }

            curr = curr->next;
        }
    }
}

void DeleteVertex(char new_val)
{ // deleting a vertex and its reference(edge) everywhere

    // first deleting all reference(edge) of the vertex you want to delete
    Vertex *main = V_head;
    while (main != NULL)
    {
        if (main->main_val != new_val)
        { // to not go in the sub list of the vertex itself
            Edge *sub = main->E_head; 
            if (sub->sub_vertex->main_val == new_val)
            { // if reference is in the start of sub list
                main->E_head = sub->next;
                free(sub);
                main = main->next;
                continue;
            }
            Edge *sub2 = main->E_head->next; // next
            while (sub2 != NULL)
            { // to find reference of the vertex in the sublist
                if (sub2->sub_vertex->main_val == new_val)
                {
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

    // now deleting the vertex along with its sub list
    main = V_head;
    Edge *sub = NULL;
    Edge *sub2;
    if (main->main_val == new_val)
    { // if the vertex is at the start
        V_head = main->next;
        sub = main->E_head;
        free(main);
    }
    else
    {
        Vertex *main2 = V_head->next; // next
        while (main2 != NULL)
        { // if the vertex is in the middle or end
            if (main2->main_val == new_val)
            {
                main->next = main2->next;
                sub = main2->E_head;
                free(main2);
                break;
            }
            main = main->next;
            main2 = main2->next;
        }
    }
    if (sub == NULL)
    {
        cout << "deleted the vertex" << endl;
        return;
    }

    sub2 = sub; // next
    while (sub != NULL)
    { // deleting sub list
        sub2 = sub2->next;
        free(sub);
        sub = sub2;
    }
    cout << "deleted the vertex" << endl;
    return;
}

void DeleteEdge(char new_val)
{ // deleting an edge from a specific vertex
    char vertex;
    cout << "Enter edge you want to delete: ";
    cin >> vertex;
    Vertex *V_curr = V_head;
    while (V_curr != NULL)
    {
        if (V_curr->main_val == vertex)
        { 
            Edge *prev = V_curr->E_head;
            if (prev == NULL)
            {
                cout << "no Edge" << endl;
                return;
            }

            else if (prev->sub_vertex->main_val == new_val)
            {
                V_curr->E_head = prev->next;
                free(prev);
                return;
            }
            Edge *E_curr = V_curr->E_head;
            E_curr = E_curr->next;
            while (E_curr != NULL)
            {
                if (E_curr->sub_vertex->main_val == new_val)
                {
                    prev->next = E_curr->next;
                    free(E_curr);
                    return;
                }
                prev = prev->next;
                E_curr = E_curr->next;
            }
            cout << "Edge not found" << endl;
            return;
        }
        V_curr = V_curr->next;
    }
    cout << "Empty" << endl;
}

void OutDegree(char new_val)
{
    Vertex *V_curr = V_head;
    while (V_curr != NULL)
    {
        if (V_curr->main_val == new_val)
        {
            cout << "vertex found" << endl;
            break;
        }
        V_curr = V_curr->next;
    }
    if (V_curr == NULL)
    {
        cout << "sub vertex not found" << endl;
        return;
    }
    int counter = 0;
    Edge *E_curr = V_curr->E_head;
    while (E_curr != NULL)
    {
        counter++;
        E_curr = E_curr->next;
    }
    cout << "Outdegree is: " << counter << endl;
}

void InDegree(char new_val)
{
    int counter = 0;
    Vertex *V_curr = V_head;
    Edge *E_curr = NULL;
    while (V_curr != NULL)
    {
        E_curr = V_curr->E_head;
        while (E_curr != NULL)
        {
            if (E_curr->sub_vertex->main_val == new_val)
            {
                counter++;
            }
            E_curr = E_curr->next;
        }
        V_curr = V_curr->next;
    }
    cout << "Indegree is: " << counter << endl;
}


int main()
{
    // InsertVertex('a');
    // InsertVertex('b');
    // InsertVertex('c');
    // InsertVertex('d');
    // InsertEdge('b');
    // InsertEdge('c');
    // InsertEdge('d');
    // PrintVertex();
    // cout<<"------------"<<endl;
    // PrintEdge();
    // cout<<"------------"<<endl;
    // DeleteEdge('b');
    // cout<<"------------"<<endl;
    // PrintVertex();
    // OutDegree('a');
    // InDegree('a');


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
			cout << "Enter vertex value: ";
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
		if (a == 7) {
			cout << "Enter the vertex you want to find: ";
			cin >> c;
			BreadthFirsttt(c);
		
		}
		if (a == 8) {
			printgraph();

		}
		if (a == 14) {
			cout << "Enter which vertex's outdegree you want to know:" << endl;
			cin >> c;
			OutDegree(c);
		}
		if (a == 15) {
			cout << "Enter which vertex's indegree you want to know:" << endl;
			cin >> c;
			InDegree(c);
		}
	}
    return 0;


}