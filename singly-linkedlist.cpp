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
            cout << "NULL\n";
        }

        void insertAtIndex(int index, int data) {
            if(index < 0) {
                cout << "incorrect position, aborting!";
                return;
            }
            Node* toInsert = new Node(data);

            // Case 1: Insert at head
            if(index == 0) {
                toInsert->next = head;
                head = toInsert;
                return;
            }

            else {
                Node* current = head;
                int i = 0;
                while(i < index -1) {
                    current = current->next; // go till previous of position of node
                    i++;
                }
                toInsert->next = current->next;
                current->next = toInsert;
            }
        }

        int length() {
            Node* current = head;
            int count = 0;
            while(current != NULL) {
                count++;
                current = current->next;
            }
            return count;
        }
};

int LinkedList::size = 0;

int main() {
    // LinkedList ll;
    // ll.pushBack(12);
    // ll.pushBack(223);
    // ll.traverse();
    // cout << endl;
    // ll.pushFront(23);
    // ll.traverse();
    // cout << endl;
    // // ll.popFront();
    // ll.popBack();
    // ll.traverse();


    LinkedList list;

    cout << "Inserting values...\n";
    list.insertAtIndex(0, 10); // head = 10
    list.traverse();

    list.insertAtIndex(1, 20); // 10 -> 20
    list.traverse();

    list.insertAtIndex(1, 15); // 10 -> 15 -> 20
    list.traverse();

    list.insertAtIndex(3, 25); // 10 -> 15 -> 20 -> 25
    list.traverse();

    list.insertAtIndex(0, 5);  // 5 -> 10 -> 15 -> 20 -> 25
    list.traverse();

    cout << "Length of list: " << list.length() << endl;

} 