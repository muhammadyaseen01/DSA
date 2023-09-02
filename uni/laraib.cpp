#include <iostream>
#include <cstdlib>

using namespace std;
struct Student
{
    int ID;
    Student* sNext;
};
struct Course
{
    int cCode;
    struct Student* sStart;
    Course* cNext;
}; struct Course *cStart;

void insertCourse()
{
    int newCode;
    cout << "Enter code of the course: ";
    cin >> newCode;
    
    Course *curr = cStart;
    while (curr != NULL)
    {
        if (curr->cCode == 0)
        {
            cout << "It is an invalid code.\n";
            return;
        }
        else if (curr->cCode == newCode)
        {
            cout << "Following code already exists in the list.\n";
            return;
        }
        curr = curr->cNext;
    }
    Course *temp = new Course;
    temp->cCode = newCode;
    temp->cNext = NULL;
    temp->sStart = NULL;

    if (cStart == NULL)
    {
        cStart = temp;
    }
    else
    {
        curr = cStart;
        while (curr->cNext != NULL)
        {
            curr = curr->cNext;
        }
        curr->cNext = temp;
    }
}

void insertStudent()
{
    int ID;
    int courseID;
    cout << "Enter ID of the student: ";
    cin >> ID;
    cout << "Enter course, student wants to enroll in: ";
    cin >> courseID;

    Course *cCurr = cStart;
    
     while (cCurr != NULL)
        {
            if (cCurr->cCode == courseID)
            {
                Student *sCurr = cCurr->sStart;
                while (sCurr != NULL)
                {
                    if (sCurr->ID == ID)
                    {
                        cout << "ID already exists!\n";
                        return;
                    }
                }
                Student *temp = new Student;
                temp->ID = ID;
                temp->sNext = NULL;

                if (cCurr->sStart == NULL)
                {
                    cCurr->sStart = temp;
                }
                else
                {
                   sCurr = cCurr->sStart;
                   while (sCurr->sNext != NULL)
                   {
                       sCurr = sCurr->sNext;
                   }
                   sCurr->sNext = temp;
                }
                return;
            }
            cCurr = cCurr->cNext;
        }
        cout << "Following course does not exist.\n";
}

void deleteStudentCourse()
{
    Course *cCurr = cStart;
    int toDelete;
    int cCode;
    cout << "Enter course, student is enrolled in: ";
    cin >> cCode;
    //Course check
    while (cCurr != NULL)
    {
        if(cCode != cCurr->cCode)
        {
            cCurr = cCurr->cNext;
        }

        else 
        {
            break;
        }
    }
    if (cCurr == NULL)
        {
            cout << "Following course does not exist.\n";
            return;
        }
    cout << "Enter ID of the student to delete: ";
    cin >> toDelete;
    Student *sCurr = cCurr->sStart;
    Student *sPrev = NULL;
    while (sCurr != NULL)
    {
        if (sCurr->ID == toDelete)
        {
            if (sPrev == NULL)
            {
            cCurr->sStart = sCurr->sNext;
            free(sCurr);
            }
            else
            {   
                sPrev->sNext = sCurr->sNext;
            }
            free(sCurr);
            cout << "ID " << toDelete << " is deleted.\n";
            return;
        }
        sPrev = sCurr;
        sCurr = sCurr->sNext;
    }
    cout << "Following student is not enrolled in this course.\n";
    return;   
}

void Print()
{
    if (cStart == NULL)
    {
    cout << "No Courses!!\n";
    return;
    }
    Course *cCurr = cStart;
    while (cCurr != NULL)
    {
        cout << "The course code is: " << cCurr->cCode << "\n";
        Student *sCurr = cCurr->sStart;
        if (sCurr == NULL)
        {
            cout << "There are currently no students enrolled in this course.\n";
        }
        else if (sCurr != NULL) 
        {
            cout << "Students enrolled in the course are: \n";
        }
        while (sCurr != NULL)
        {
            cout << sCurr->ID << "\n";
            sCurr = sCurr->sNext;
        }
        cout << "\n";
        cCurr = cCurr->cNext;
    }
}

void search ()
{
    bool studentFound = false;
    cout << "Enter ID of the student to search: ";
    int toSearch;
    cin >> toSearch;
    Course *cCurr = cStart;
    cout << "The student is enrolled in the following courses:\n";
    while(cCurr != NULL)
    {
        Student *sCurr = cCurr->sStart;
        while (sCurr != NULL)
        {
            if (sCurr->ID == toSearch)
            {
                cout << cCurr->cCode << "\n"; 
            }
            sCurr = sCurr->sNext;
        }
        cCurr = cCurr->cNext;
        sCurr = cCurr->sStart;
    }
    return;
    if (studentFound == false)
    {
        cout << "Following student is not enrolled in any course.\n";
    }
}

void deletion ()
{
    bool studentFound = false;
    cout << "Enter ID of the student to delete: ";
    int toDelete;
    cin >> toDelete;
    Course *cCurr = cStart;
    while(cCurr != NULL)
    {
        Student *sCurr = cCurr->sStart;
        Student *sPrev = NULL;
        while (sCurr != NULL)
        {
            if (sCurr->ID == toDelete)
            {
                if (sPrev == NULL)
                {
                    cCurr->sStart = sCurr->sNext;
                }
                else
                {
                    sPrev->sNext = sCurr->sNext;
                }
                free(sCurr);
                studentFound = true;
                break;
            }
            sPrev = sCurr;
            sCurr = sCurr->sNext;
        }
        cCurr = cCurr->cNext;
    }
    return;
    if (studentFound == false)
    {
        cout << "Following student is not enrolled in any course.\n";
    }
}

void deleteACourse()
{
    
}

int main()
{
    int opt;
    cout << "\t 1: Enter a course. \n";
    cout << "\t 2: Enroll a student to a course. \n";
    cout << "\t 3: Delete a student from a course. \n";
    cout << "\t 4: Print. \n";
    cout << "\t 5: Search for a student. \n";
    cout << "\t 6: Delete a student from all courses. \n";
    cout << "\t 0: Exit. \n";
    cin >> opt;
    
    while (opt != 0)
    {
        if (opt == 1)
        {
        insertCourse();
        }
        if (opt == 2)
        {
        insertStudent();
        }
        if (opt == 3)
        {
        deleteStudentCourse();
        }
        if (opt == 4)
        {
            Print();
        }
        if (opt == 5)
        {
            search();
        }
        if (opt == 6)
        {
            deletion();
        }
        cout << "\t 1: Enter a course. \n";
        cout << "\t 2: Enroll a student to a course. \n";
        cout << "\t 3: Delete a student from a course. \n";
        cout << "\t 4: Print. \n";
        cout << "\t 5: Search for a student. \n";
        cout << "\t 6: Delete a student from all courses. \n";
        cout << "\t 0: Exit. \n";
        cin >> opt;
    }
    return 0;
}