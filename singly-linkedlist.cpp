#include<iostream>
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
        static int size;
        LinkedList() {
            this->head = nullptr;
        }
        bool isEmpty() {
            return size == 0;
        }
        void pushBack(int data) {
            Node* newNode = new Node(data);
            if(isEmpty()) {
                this->head = newNode;
            }
            else {
                Node* current = head;
                while(current->next != nullptr) {
                    current = current->next;
                }
                current->next = newNode;
            }
            size++;
        }

        void pushFront(int data) {
            Node* newNode = new Node(data);
            if(isEmpty()) {
                this->head = newNode;
            }
            else {
                newNode->next = head;
                head = newNode;
            }
            size++;
        }

        void popFront() {
            if(isEmpty()) {
                cout << "LinkedList is Empty!";
                return;
            }
            else {
                Node* temp = head;
                head = temp->next;
                delete temp;
            }
            size--;
        }


        void popBack() {
            if(isEmpty()) {
                cout << "LinkedList is Empty!";
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
            size--;
        }
        void traverse() {
            Node* current = head;
            while(current != nullptr) {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "NULL";
        }
};

int LinkedList::size = 0;

int main() {
    LinkedList ll;
    ll.pushBack(12);
    ll.pushBack(223);
    ll.traverse();
    cout << endl;
    ll.pushFront(23);
    ll.traverse();
    cout << endl;
    // ll.popFront();
    ll.popBack();
    ll.traverse();

} 