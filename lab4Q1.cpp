#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

// Function to push a value into the stack
void push(int stack[], int &top, int value, string stackName)
{
    if (top == MAX_SIZE - 1)
    {
        cout << stackName << " Stack is Full! Cannot push " << value << "." << endl;
        return;
    }

    top++;
    stack[top] = value;

    cout << value << " pushed into " << stackName << " Stack." << endl;
}

// Function to pop a value from the stack
void pop(int stack[], int &top, string stackName)
{
    if (top == -1)
    {
        cout << stackName << " Stack is Empty! Nothing to pop." << endl;
        return;
    }

    cout << stack[top] << " popped from " << stackName << " Stack." << endl;
    top--;
}

// Function to display count and sum
void displayResult(int stack[], int top, string stackName)
{
    int count = 0;
    int sum = 0;

    for (int i = 0; i <= top; i++)
    {
        count++;
        sum += stack[i];
    }

    cout << "\n" << stackName << " Stack:" << endl;
    cout << "Total Values: " << count << endl;
    cout << "Sum: " << sum << endl;
}

int main()
{
    int evenStack[MAX_SIZE];
    int oddStack[MAX_SIZE];

    int evenTop = -1;
    int oddTop = -1;

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
                push(evenStack, evenTop, value, "Even");
            }
            else
            {
                push(oddStack, oddTop, value, "Odd");
            }
            break;

        case 2:
            pop(evenStack, evenTop, "Even");
            break;

        case 3:
            pop(oddStack, oddTop, "Odd");
            break;

        case 4:
            displayResult(evenStack, evenTop, "Even");
            displayResult(oddStack, oddTop, "Odd");
            break;

        case 5:
            cout << "\nProgram Ended." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}