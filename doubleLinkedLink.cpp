#include<iostream>
using namespace std;

class EditorState {
public:
    string content;
    EditorState* next;
    EditorState* prev;
};

// Class for the text editor's history (Doubly Linked List)
class EditorHistory {
private:
    EditorState* currentState;

public:
    EditorHistory() {
        currentState = nullptr;
    }

    // Function to add a new state to the history (undo operation)
    void addState(string content){
        EditorState* newState = new EditorState;
        newState->content = content;
        newState->next = nullptr;

        if (currentState == nullptr)
            newState->prev = nullptr;
        else{
            newState->prev = currentState;
            currentState->next = newState;
        }

        currentState = newState;
    }

    // Function to perform undo (move to the previous state)
    bool undo() {
        if (currentState == nullptr || currentState->prev == nullptr)
            return false; // Nothing to undo

        currentState = currentState->prev;
        return true;
    }

    // Function to perform redo (move to the next state)
    bool redo() 
        if (currentState == nullptr || currentState->next == nullptr)
            return false; // Nothing to redo

        currentState = currentState->next;
        return true;
    }

    // Function to display the current state (content)
    void displayCurrentState() {
        if (currentState == nullptr)
            cout << "Text editor is empty." << endl;
        else{
            cout << "Current content:" << endl;
            cout << currentState->content << endl;
        }
    }
};

int main(){

}