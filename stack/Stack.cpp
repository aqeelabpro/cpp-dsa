#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }    
};

class Stack {
private:
    Node* top;

public:
    Stack() { top = nullptr; }

    void push(int data) {
        Node* el = new Node(data);
        el->next = top;
        top = el;
    }

    bool pop() {
        if (isEmpty()) {
            return false;
        }
        Node* toRemove = top;
        top = top->next;
        delete toRemove;
        return true;
    }

    int peek() {
        if (isEmpty()) {
            return -1; // indicates empty
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    // For debugging: print stack from top to bottom
    void print() {
        Node* curr = top;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    Stack undoStack;
    Stack redoStack;
    int choice, value;

    while (true) {
        cout << "\n1. Perform action (type number)\n";
        cout << "2. Undo\n";
        cout << "3. Redo\n";
        cout << "4. Show current stack\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter a number (action): ";
            cin >> value;
            undoStack.push(value);
            redoStack.clear(); // new action invalidates redo
            cout << "Action performed: " << value << endl;
        } 
        else if (choice == 2) {
            if (undoStack.isEmpty()) {
                cout << "Nothing to undo!\n";
            } else {
                int lastAction = undoStack.peek();
                undoStack.pop();
                redoStack.push(lastAction);
                cout << "Undone action: " << lastAction << endl;
            }
        } 
        else if (choice == 3) {
            if (redoStack.isEmpty()) {
                cout << "Nothing to redo!\n";
            } else {
                int redoAction = redoStack.peek();
                redoStack.pop();
                undoStack.push(redoAction);
                cout << "Redone action: " << redoAction << endl;
            }
        } 
        else if (choice == 4) {
            cout << "Current undo stack (top -> bottom): ";
            undoStack.print();
        } 
        else if (choice == 5) {
            break;
        } 
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
