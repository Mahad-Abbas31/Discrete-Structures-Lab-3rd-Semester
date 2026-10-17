#include <iostream>
#include <string>
using namespace std;

// ============================================================
// Airline Boarding List - Doubly Linked List
// ============================================================

// Passenger Node
struct Passenger
{
    int passengerID;
    string passengerName;
    string seatNumber;
    string passengerClass;
    Passenger* prev;
    Passenger* next;
};

// Head and Tail pointers
Passenger* head = NULL;
Passenger* tail = NULL;


// ============================================================
// Function to create a new passenger node
// ============================================================
Passenger* createPassenger(int id, string name, string seat, string pClass)
{
    Passenger* newPassenger = new Passenger;

    newPassenger->passengerID = id;
    newPassenger->passengerName = name;
    newPassenger->seatNumber = seat;
    newPassenger->passengerClass = pClass;

    newPassenger->prev = NULL;
    newPassenger->next = NULL;

    return newPassenger;
}


// ============================================================
// Task 2 - Insert initial passengers at the end
// ============================================================
void insertAtEnd(int id, string name, string seat, string pClass)
{
    Passenger* newPassenger =
        createPassenger(id, name, seat, pClass);

    // If list is empty
    if (head == NULL)
    {
        head = newPassenger;
        tail = newPassenger;
    }
    else
    {
        newPassenger->prev = tail;
        tail->next = newPassenger;
        tail = newPassenger;
    }
}


// ============================================================
// Task 3 - Insert at Beginning
// ============================================================
void insertAtBeginning(int id, string name, string seat, string pClass)
{
    Passenger* newPassenger =
        createPassenger(id, name, seat, pClass);

    // If list is empty
    if (head == NULL)
    {
        head = newPassenger;
        tail = newPassenger;
    }
    else
    {
        newPassenger->next = head;
        head->prev = newPassenger;
        head = newPassenger;
    }
}


// ============================================================
// Task 5 - Delete from End
// ============================================================
void deleteFromEnd()
{
    // If list is empty
    if (head == NULL)
    {
        cout << "The boarding list is empty." << endl;
        return;
    }

    // If there is only one passenger
    if (head == tail)
    {
        delete tail;
        head = NULL;
        tail = NULL;
    }
    else
    {
        Passenger* temp = tail;

        tail = tail->prev;
        tail->next = NULL;

        delete temp;
    }

    cout << "Last passenger has been removed." << endl;
}


// ============================================================
// Display passengers from Head to Tail
// ============================================================
void displayForward()
{
    Passenger* current = head;

    cout << "\n========== Boarding List (Forward) ==========\n";

    if (current == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    while (current != NULL)
    {
        cout << "Passenger ID   : " << current->passengerID << endl;
        cout << "Passenger Name : " << current->passengerName << endl;
        cout << "Seat Number    : " << current->seatNumber << endl;
        cout << "Class          : " << current->passengerClass << endl;

        cout << "--------------------------------------------" << endl;

        current = current->next;
    }
}


// ============================================================
// Display passengers from Tail to Head
// ============================================================
void displayBackward()
{
    Passenger* current = tail;

    cout << "\n========== Boarding List (Backward) ==========\n";

    if (current == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    while (current != NULL)
    {
        cout << "Passenger ID   : " << current->passengerID << endl;
        cout << "Passenger Name : " << current->passengerName << endl;
        cout << "Seat Number    : " << current->seatNumber << endl;
        cout << "Class          : " << current->passengerClass << endl;

        cout << "---------------------------------------------" << endl;

        current = current->prev;
    }
}


// ============================================================
// Verify Head and Tail links
// ============================================================
void verifyLinks()
{
    cout << "\n========== Link Verification ==========\n";

    if (head != NULL)
    {
        if (head->prev == NULL)
            cout << "Head->prev = NULL : Correct" << endl;
        else
            cout << "Head->prev = NULL : Incorrect" << endl;
    }

    if (tail != NULL)
    {
        if (tail->next == NULL)
            cout << "Tail->next = NULL : Correct" << endl;
        else
            cout << "Tail->next = NULL : Incorrect" << endl;
    }

    cout << "Head Passenger : "
         << head->passengerName << endl;

    cout << "Tail Passenger : "
         << tail->passengerName << endl;
}


// ============================================================
// Main Function
// ============================================================
int main()
{
    // ========================================================
    // Task 1 - Initialize an empty doubly linked list
    // ========================================================

    head = NULL;
    tail = NULL;

    cout << "Doubly Linked List initialized as empty." << endl;


    // ========================================================
    // Task 2 - Create Initial Passengers
    // ========================================================

    insertAtEnd(101, "Ali Khan", "12A", "Economy");
    insertAtEnd(102, "Sara Ahmed", "12B", "Economy");
    insertAtEnd(103, "Usman Malik", "14C", "Business");
    insertAtEnd(104, "Ayesha Noor", "15A", "Economy");
    insertAtEnd(105, "Hamza Shah", "16B", "Business");

    cout << "\nInitial Passengers Created.";

    displayForward();


    // ========================================================
    // Task 3 - Insert VIP Passenger at Beginning
    // ========================================================

    cout << "\n\nAdding VIP passenger at the beginning...";

    insertAtBeginning(100, "Mr. Ahmed", "1A", "First Class");

    displayForward();

    cout << "\nChecking links after insertion:";
    verifyLinks();


    // ========================================================
    // Task 4 - Insert Passenger at End
    // ========================================================

    cout << "\n\nAdding a new passenger at the end...";

    insertAtEnd(106, "Zain Abbas", "18C", "Economy");

    displayForward();

    cout << "\nChecking tail after insertion:";
    verifyLinks();


    // ========================================================
    // Task 5 - Delete Passenger from End
    // ========================================================

    cout << "\n\nDeleting the last passenger...";

    deleteFromEnd();

    displayForward();

    cout << "\nChecking new last passenger:";
    verifyLinks();


    // ========================================================
    // Display the list in reverse direction
    // ========================================================

    displayBackward();


    return 0;
}