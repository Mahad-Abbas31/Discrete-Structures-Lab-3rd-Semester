#include<iostream>
using namespace std;

class Student{
    public:
    string name;
    string enroll;
    double marks;
    
    Student(){}
    Student(string n, string e, double m):name(n),enroll(e),marks(m){}
    
    void display() const {
        cout << "Name: " << name
             << ", Enroll: " << enroll
             << ", Marks: " << marks << endl;       
    }
};

class Node{
    public:
    Node* next;
    Student data;

    Node(Student s):data(s),next(nullptr) {}

};

class Stack {
    private:
    Node* top; // Pointer to top of stack
    
    public:
    Stack() { top = nullptr; }
    
    bool isEmpty() {
        return top == nullptr;
    }
    
    void push(Student s) {
        Node* newNode = new Node(s);
        newNode->next = top;
        top = newNode;
        cout << "Student pushed: " << s.name ;
    }
    
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        
        Node* temp = top;

        cout << "Popping student: " <<
        top->data.name << endl;        
        top = top->next;
        
        delete temp;
    }
    
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        
        cout << "Top Student -> ";
        top->data.display();
    }
    
    void displayStack() {      
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        
        Node* current = top;
        cout << "\n--- Student Stack ---\n";
        
        while (current != nullptr) {            
            current->data.display();
            current = current->next;
        }
        cout << "---------------------\n";
    }
};

int main(){
    Stack s;

    Student s1("Mahad Abbas", "BSCS", 99);
    Student s2("Taha Waqar", "BSCS", 99);
    Student s3("Abdul Sami", "BSCS", 99);

    s.push(s1);
    s.push(s2);
    s.push(s3);

    s.displayStack();
    
    s.pop();
    s.displayStack();
    
    s.pop();
    s.displayStack();

}