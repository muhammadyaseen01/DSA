#include <iostream>
#include <cstdlib>
using namespace std;

struct Student
{
    int ID;
    Student *std_next;
};

struct Course
{
    int C_code;
    Course *crs_next;
    Student *std_head;
};
Course *crs_head = NULL;

void course_insertAtHead()
{
    int new_id;
    cout << "enter the course code you want to insert: ";
    cin >> new_id;

    Course *new_node = new Course; // memory allocate for new node
    new_node->C_code = new_id;     // new node k code section me course code enter
    new_node->crs_next = crs_head; // new node k next me head(NULL) enter
    crs_head = new_node;           // head ko new node par point (it means linked list starting from there where head pointed)
}
void course_insertAtTail()
{
    if (crs_head == NULL) // pehle node null means linked list empty to head pr insertion
    {
        course_insertAtHead();
        return;
    }

    else
    {
        int code; // take input
        cout << "enter the course code you want to insert: ";
        cin >> code;

        Course *new_node = new Course; // initialize node and add code and next to null
        new_node->C_code = code;
        new_node->crs_next = NULL;
        // //error line
        // new_node->std_head = NULL; //tail (last me add kr rhay is liye next ko null kr rhay hain)
        Course *crs_curr = crs_head;       // agr list me elements hain to last element tk move krnge uske liye ek curr ptr initialize
        while (crs_curr->crs_next != NULL) // jab tk curr ka next null nh hojata tab tak curr ko agy move krnge
        {                                  // curr k next null hony ka matlab curr point the last element of the list
            crs_curr = crs_curr->crs_next; // moving curr ptr
        }
        crs_curr->crs_next = new_node; // jab curr ka next null to matlab curr last element ko point kr rha to curr k next me new node add krdnge
    }
}
void course_insertAtAnyPosition()
{
    int n;
    cout << "\t 1. Press 1 to insert at start of the list: " << endl;
    cout << "\t 2. Press 2 to insert at last of the list: " << endl;
    cout << "\t 3. Press 3 to insert at arbitrary position of the list: " << endl;
    cin >> n;

    if (n == 1)
    {
        course_insertAtHead();
        return;
    }
    else if (n == 2)
    {
        course_insertAtTail();
        return;
    }
    else if (n == 3)
    {
        int node_index, code, curr_pos = 0; // current_position = 0 (loop chalane k liye)
        cout << "enter the index no where you want to insert a node: ";
        cin >> node_index;
        cout << "enter the code which you want to insert a that node: ";
        cin >> code;

        Course *crs_curr = crs_head; // curr ko head se initialze krnge
        while (curr_pos != node_index - 1)
        {                                  // curr_pos = 0, 0 se input index -1 tak move krnge curr ptr ko (index - 1 is liye qk jis index par insert krna h us se pehle walay index par mera curr ptr point krne lag jayega to uske next me new node add kr sakta hun (by adding curr->next to new_node->next me))
            crs_curr = crs_curr->crs_next; // curr ptr ko move krnge
            curr_pos++;                    // position me increament
        }

        // Course* new_node = new Course;
        // new_node->C_code = code;
        // new_node->crs_next = crs_curr->crs_next;
        // crs_curr->crs_next = new_node;

        // if(crs_curr == NULL){
        //     cout<< "Invalid position, Node not inserted!"<<endl;

        // }

        // agr user ne wo index input krdia jo list me exist nhi krta to usko tackle krne k liye ye condition
        if (crs_curr != NULL)
        { // agr curr = null hoga to new node ko uske next se kese point kr saknga is liye (jab tak curr not  =to null to insertion ho sakegi)
            Course *new_node = new Course;
            new_node->C_code = code;
            new_node->crs_next = crs_curr->crs_next;
            crs_curr->crs_next = new_node;
        }
        else
        { // otherwise invalid index ka error dedega
            cout << "Invalid position, Node not inserted!" << endl;
        }
    }
}

void student_insertion()
{
    int std_id, crs_id;
    cout << "enter the course id where you want to enroll: ";
    cin >> crs_id;
    cout << "enter the student id: ";
    cin >> std_id;

    Course *crs_curr = crs_head;
    while (crs_curr != NULL)
    {
        if (crs_curr->C_code == crs_id)
        {
            Student *std_curr = crs_curr->std_head;
            // while (std_curr!= NULL)
            // {
            //     cout << "okay" << endl;
            //     if (std_curr->ID == std_id)
            //     {
            //         cout << "ID already exist! ";
            //         return;
            //     }
            //     std_curr = std_curr->std_next;
            // }
            Student *new_node = new Student;
            new_node->ID = std_id;
            new_node->std_next = NULL;

            cout << "okay" << endl;
            if (crs_curr->std_head == NULL)
            {
                crs_curr->std_head = new_node;
                cout << "std enrolled" << endl;
                cout << crs_curr->std_head->ID << endl;
            }
            else
            {
                std_curr = crs_curr->std_head;
                while (std_curr->std_next != NULL)
                {
                    std_curr = std_curr->std_next;
                }
                std_curr->std_next = new_node;
                cout << "std enrolled" << endl;
            }
            // cout<<"Student enrolled!";
            return;
        }
        crs_curr = crs_curr->crs_next;
    }
    cout << "There is no course exist! ";
}

void delete_student()
{
    int std_id, crs_id;
    cout << "enter the course id where you want to delete: ";
    cin >> crs_id;
    cout << "enter the student id: ";
    cin >> std_id;

    Course *crs_curr = crs_head;
    while (crs_curr != NULL)
    {
        if (crs_curr->C_code == crs_id)
        {
            Student *std_curr = crs_curr->std_head;
            Student *std_prev = crs_curr->std_head;
            if (std_curr == NULL)
            {
                cout << "No student Enrolled!" << endl;
                return;
            }
            else if (std_curr->std_next == NULL)
            { // list have only one(1) node
                free(std_curr);
                crs_curr->std_head = NULL;
                return;
            }
            std_curr = std_curr->std_next; // ek step agy krdia h prev se ab isse delete krna hua to iska next prev k next me daal dnga
            while (std_curr != NULL)
            {
                if (std_curr->ID == crs_id)
                { // prev is one node previous to curr
                    std_prev->std_next = std_curr->std_next;
                    free(std_curr);
                    return;
                }
                std_prev = std_prev->std_next;
                std_curr = std_curr->std_next;
            }
        }
        crs_curr = crs_curr->crs_next;
    }
    cout << "Course doesn't exist!" << endl;
}

void display()
{
    Course *crs_curr = new Course;
    crs_curr = crs_head;
    while (crs_curr != NULL)
    {
        // cout << "The course code is:" << crs_curr->C_code ;
        cout << crs_curr->C_code << "-->";
        crs_curr = crs_curr->crs_next;
    }
    cout << "NULL" << endl;
}

// int main()
// {
//     course_insertAtTail();
//     course_insertAtTail();
//     course_insertAtTail();
//     course_insertAtTail();
//     display();
//     course_insertAtAnyPosition();
//     display();

//     return 0;
// }

int main()
{
    course_insertAtTail();

    display();
    cout<<"okay";
    // course_insertAtAnyPosition();
    // display(); // Add this line to display the updated list after inserting at any position

    student_insertion();
    student_insertion();
    display();

    return 0;
}