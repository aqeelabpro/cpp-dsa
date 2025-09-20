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

class LinkedList {
private:
    Node* head;
public:    
    LinkedList() : head(nullptr) {}

    bool isEmpty() {
        return head == nullptr;
    }

    void pushBack(int data) {
        Node* newNode = new Node(data);
        if(isEmpty()) {
            head = newNode;
        }
        else {
            Node* current = head;
            while(current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void pushFront(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void popFront() {
        if(isEmpty()) {
            cout << "LinkedList is Empty!\n";
            return;
        }
        Node* temp = head;
        head = temp->next;
        delete temp;
    }

    void popBack() {
        if(isEmpty()) {
            cout << "LinkedList is Empty!\n";
            return;
        }
        if(!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while(temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void traverse() {
        Node* current = head;
        while(current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    void insertAtIndex(int index, int data) {
        if(index < 0) {
            cout << "Incorrect position!\n";
            return;
        }
        Node* toInsert = new Node(data);

        if(index == 0) {
            toInsert->next = head;
            head = toInsert;
            return;
        }

        Node* current = head;
        for(int i = 0; i < index - 1 && current != nullptr; i++) {
            current = current->next;
        }

        if(current == nullptr) {
            cout << "Index out of range!\n";
            delete toInsert;
            return;
        }

        toInsert->next = current->next;
        current->next = toInsert;
    }

    int length() {
        int count = 0;
        Node* current = head;
        while(current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    Node* getHead() {
        return head;
    }
};

Node* mergeSorted(Node* head1, Node* head2) {
    if(!head1) return head2;
    if(!head2) return head1;

    Node* head = nullptr;

    if(head1->data <= head2->data) {
        head = head1;
        head->next = mergeSorted(head1->next, head2);
    }
    else {
        head = head2;
        head->next = mergeSorted(head1, head2->next);
    }
    return head;
}

int main() {
    LinkedList l1;
    l1.pushBack(1);
    l1.pushBack(3);
    l1.pushBack(5);
    l1.pushBack(7);

    LinkedList l2;
    l2.pushBack(2);
    l2.pushBack(4);
    l2.pushBack(6);
    l2.pushBack(8);

    cout << "List 1: ";
    l1.traverse();

    cout << "List 2: ";
    l2.traverse();

    Node* merged = mergeSorted(l1.getHead(), l2.getHead());

    cout << "Merged List: ";
    while(merged) {
        cout << merged->data << " -> ";
        merged = merged->next;
    }
    cout << "NULL\n";

    return 0;
}
