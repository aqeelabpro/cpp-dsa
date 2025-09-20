#include<iostream>
using namespace std;



class Node {
    public:
        int data;
        Node* next;
    public:
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }    
};


class CircularLinkedList {
    private:
        Node* head;
    public:
        CircularLinkedList() {
            head = nullptr;
        }
        void push_back(int data) {
            Node* newNode = new Node(data);
            if(head == nullptr) {
                head = newNode;
                head->next = head; // point next to itself
                return;
            }
            else {
                Node* current = head;
                while(current->next != head) {
                    current = current->next;
                }
                current->next = newNode;
                newNode->next = head; // point to head
            }
        }   
        
        void push_front(int data) {
            Node* newNode = new Node(data);
            if(head == nullptr) {
                head = newNode;
                head->next = head; // point next to itself
                return;
            }
            else {
                Node* current = head;
                while(current->next != head) {
                    current = current->next;
                }
                current->next = newNode;
                newNode->next = head; // point to head
                head = newNode;
            }
        }

        void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
        cout << "(head)" << endl;
    }

    void createCycle(int position) {
    if (!head) return;

    Node* tail = head;
    Node* cycleNode = nullptr;
    int count = 0;

    do {
        if (count == position) {
            cycleNode = tail; // save the node where cycle should start
        }
        tail = tail->next;
        count++;
    } while (tail->next != nullptr && tail->next != head); // stop at end

    if (tail && cycleNode) {
        tail->next = cycleNode; // create cycle
    }
}


    bool containsCycle() {
        Node* slow = head;
        Node* fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            return true; // cycle detected
        }
        return false;

        // return head != nullptr;
    }
};

int main() {
    CircularLinkedList cll;

    cll.push_back(10);
    cll.push_back(20);
    cll.push_back(30);
    cll.push_back(40);

    cout << "Contains cycle? " << (cll.containsCycle() ? "Yes" : "No") << endl;

    // Create a cycle manually: link last node to the second node
    cll.createCycle(1);

    cout << "After creating cycle, contains cycle? " << (cll.containsCycle() ? "Yes" : "No") << endl;

    return 0;
}
