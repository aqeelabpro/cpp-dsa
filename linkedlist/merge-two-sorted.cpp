#include<iostream>
using namespace std;

// Node class to represent each doubly linkedlist node
class Node {
    public:
        int data;
        Node* next;
        Node* prev;
    public:
        Node(int data) {
            this->data = data;
            this->next = this->prev = NULL;
        }    
};


// doubly linked list class to insert nodes, delete nodes
class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList() {
            this->head = this->tail = NULL;
        }    

        // insert at beginning
        void InsertAtBegin(int data) {
            Node* newNode = new Node(data);
            if(IsEmpty()) {
                head = tail = newNode;
                return;
            }
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        // insert at end
        void InsertAtEnd(int data) {
            Node* newNode = new Node(data);
            if(IsEmpty()) {
                head = tail = newNode;
                return;
            }
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        Node* getHead() { return head; }
        Node* getTail() { return tail; }

        // if head is NULL, then the list is empty
        bool IsEmpty() { return head == NULL; }

        // merge two sorted doubly linked lists
        Node* merge(Node* headA, Node* headB) {
            if (!headA) return headB;
            if (!headB) return headA;

            Node* head = nullptr;

            if (headA->data <= headB->data) {
                head = headA;
                head->next = merge(headA->next, headB);
                if (head->next) head->next->prev = head;  // fix prev pointer
            } else {
                head = headB;
                head->next = merge(headA, headB->next);
                if (head->next) head->next->prev = head;  // fix prev pointer
            }
            return head;
        }

        // wrapper to merge with another DLL
        void MergeWith(DoublyLinkedList &other) {
            head = merge(head, other.head);

            // update tail after merging
            tail = head;
            while (tail && tail->next) {
                tail = tail->next;
            }
        }

        // traverse the list
        void Display() {
            Node* current = head;
            while(current != NULL) {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "NULL" << endl;
        }
};


int main() {

    DoublyLinkedList dll1;
    dll1.InsertAtEnd(1);
    dll1.InsertAtEnd(3);
    dll1.InsertAtEnd(5);

    DoublyLinkedList dll2;
    dll2.InsertAtEnd(2);
    dll2.InsertAtEnd(4);
    dll2.InsertAtEnd(6);

    cout << "List 1: ";
    dll1.Display();

    cout << "List 2: ";
    dll2.Display();

    // merge dll2 into dll1
    dll1.MergeWith(dll2);

    cout << "Merged List: ";
    dll1.Display();

    return 0;
}
