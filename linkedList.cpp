#include<iostream>
using namespace std;

class Student{
    public:
    int roll;
    string name;

    Student(int r, string n):roll(r), name(n){}
};

class Node{
    public:
    Node *next;
    int marks;
    Student s;

    Node(int r, string n, int m) : s(r,n), marks(m), next(nullptr){}
};

class LinkedList{
    Node* head;
    Node* tail;
    
    public:
    // ___ Constructor
    LinkedList():head(nullptr), tail(nullptr){}

    // ___ Push Front
    void pushFront(int r, string n, int m){
        Node* newNode = new Node(r, n, m);

        if(head == nullptr){
            head = tail = newNode;
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    // ___ Push Back
    void pushBack(int r, string n, int m){
        Node* newNode = new Node(r, n, m);

        if(head == nullptr){
            head = tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
            return;
        }
    }

    void insert(int search, int r, string n, int m){
        Node *newNode = new Node(r, n,m);
        Node *temp = head;

        while(temp != nullptr){
            if(temp->s.roll == search){
                newNode->next = temp->next;
                temp->next = newNode;

                if(temp == tail)
                    tail = newNode;
                
                return;
            }
            temp = temp->next;
        }
        delete newNode;
    }

    void popFront(){
        if(head == nullptr)
            return;
    
        Node* temp = head;
        head = head->next;
    
        if(head == nullptr)
            tail = nullptr;
    
        delete temp;
    }

    void popBack(){
        if(head == nullptr)
            return;

        if(head == tail){
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = head;

        while(temp != nullptr){
            if(temp->next == tail){
                Node* oldTail = tail;

                tail = temp;
                tail->next = nullptr;

                delete oldTail;
                return;
            }

            temp = temp->next;
        }
    }

    // ___ Reverse LinkedList
    void reverseList(){
        Node* current = head;
        Node* next = nullptr;
        Node* prev = nullptr;

        tail = head;

        while (current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    // ___ Middle Function1
    void middle(){
        int size = 0;
        Node* temp = head;
        while(temp!=nullptr){
            size++;
            temp = temp->next;
        }

        temp = head;
        int iterate = 0;
        while(iterate!= (size/2)){
            temp = temp->next;
            iterate++;
        }

        cout << temp->s.name << " " << temp->s.roll << " " << temp->marks << endl;
    }

    // ___ Miidle Function2
    void mid(){
        Node* fast = head;
        Node* slow = head;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        cout << slow->s.name << " " << slow->s.roll << " " << slow->marks << endl;
    }

    // ___ Print
    void printList(){
        Node* index = head;

        while(index!=NULL){
            cout << index->s.name << " " << index->s.roll << " " << index->marks << endl;
            index = index->next;
        }
        cout << "---------------------------\n";
    }
};

int main(){
    LinkedList ll;
    ll.pushFront(2501360, "Taha Waqar", 97);
    ll.pushFront(2501363, "Ayesha Nadeem", 70);
    ll.pushFront(2501366, "Mahad Abbas", 100);
    ll.pushFront(2501369, "Tooba Fatima", 88);
 
    ll.printList();

    ll.reverseList();
    ll.printList();

    ll.pushBack(2501372, "Salma", 81);
    ll.printList();
    
    ll.popBack();
    ll.popFront();
    ll.printList();
    
    ll.insert(2501363, 2501378, "Sara", 90);
    ll.insert(2501366, 2501381, "Salman", 70);
    ll.printList();

    ll.middle();
    ll.mid();
    
    return 0;
}