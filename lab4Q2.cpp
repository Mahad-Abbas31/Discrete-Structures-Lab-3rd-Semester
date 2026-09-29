#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

// Function to push a value into the stack
void push(Node *&top, int value, string stackName)
{
    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    cout << value << " pushed into " << stackName << " Stack." << endl;
}

// Function to pop a value from the stack
void pop(Node *&top, string stackName)
{
    if (top == nullptr)
    {
        cout << stackName << " Stack is Empty! Nothing to pop." << endl;
        return;
    }

    Node *temp = top;

    cout << temp->data << " popped from " << stackName << " Stack." << endl;

    top = top->next;

    delete temp;
}

// Function to display count and sum
void displayResult(Node *top, string stackName)
{
    int count = 0;
    int sum = 0;

    Node *temp = top;

    while (temp != nullptr)
    {
        count++;
        sum += temp->data;
        temp = temp->next;
    }

    cout << "\n" << stackName << " Stack:" << endl;
    cout << "Total Values: " << count << endl;
    cout << "Sum: " << sum << endl;
}

// Function to delete all remaining nodes
void clearStack(Node *&top)
{
    while (top != nullptr)
    {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

int main()
{
    Node *evenTop = nullptr;
    Node *oddTop = nullptr;

    int choice;
    int value;

    do
    {
        cout << "\n========== STACK MENU ==========" << endl;
        cout << "1. Push Value" << endl;
        cout << "2. Pop Even Value" << endl;
        cout << "3. Pop Odd Value" << endl;
        cout << "4. Display Results" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;

            if (value % 2 == 0)
            {
                push(evenTop, value, "Even");
            }
            else
            {
                push(oddTop, value, "Odd");
            }
            break;

        case 2:
            pop(evenTop, "Even");
            break;

        case 3:
            pop(oddTop, "Odd");
            break;

        case 4:
            displayResult(evenTop, "Even");
            displayResult(oddTop, "Odd");
            break;

        case 5:
            cout << "\nProgram Ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    // Free remaining dynamically allocated memory
    clearStack(evenTop);
    clearStack(oddTop);

    return 0;
}