#include <iostream>
using namespace std;

// Node class to represent each circular linked list node
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = this->prev = nullptr;
    }
};

// Circular linked list class
class CircularLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularLinkedList() {
        head = tail = nullptr;
    }

    Node* getHead() { return head; }
    Node* getTail() { return tail; }

    // Insert at beginning
    void InsertAtBegin(int data) {
        Node* newNode = new Node(data);
        if (IsEmpty()) {
            head = tail = newNode;
            head->next = head->prev = head;
            return;
        }

        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }

    // Concatenate two circular doubly linked lists
    Node* mergeCircular(Node* head1, Node* head2) {
        if (!head1) return head2;
        if (!head2) return head1;

        Node* tail1 = head1->prev;
        Node* tail2 = head2->prev;

        // Connect tail1 to head2
        tail1->next = head2;
        head2->prev = tail1;

        // Connect tail2 to head1 to restore circularity
        tail2->next = head1;
        head1->prev = tail2;

        return head1;
    }

    // Check if list is empty
    bool IsEmpty() {
        return head == nullptr;
    }

    // Display circular list
    void Display() {
        if (IsEmpty()) return;
        Node* current = head;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << "NULL" << endl;
    }

    // Delete last node
    void DeleteAtEnd() {
        if (IsEmpty()) return;
        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
    }
};

int main() {
    CircularLinkedList cll;
    CircularLinkedList cll2;

    // --- Insert at beginning ---
    cout << "--- Inserting at Beginning ---" << endl;
    cll.InsertAtBegin(5);
    cll.InsertAtBegin(3);
    cll.InsertAtBegin(1); 
    cout << "List 1: ";
    cll.Display();

    cll2.InsertAtBegin(6);
    cll2.InsertAtBegin(4);
    cll2.InsertAtBegin(2);
    cout << "List 2: ";
    cll2.Display();

    // --- Delete last element ---
    cout << "\n--- Delete Last Element ---" << endl;
    cll.DeleteAtEnd(); // removes 5
    cout << "List 1 after DeleteAtEnd: ";
    cll.Display();

    cll2.DeleteAtEnd(); // removes 6
    cout << "List 2 after DeleteAtEnd: ";
    cll2.Display();

    // --- Merge / Concatenate ---
    cout << "\n--- Merging(no sort as no sorting mentioned) ---" << endl;
    Node* mergedHead = cll.mergeCircular(cll.getHead(), cll2.getHead());
    cout << "Merged Circular List: ";
    Node* current = mergedHead;
    if (current) {
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != mergedHead);
        cout << "NULL" << endl;
    }

    return 0;
}
