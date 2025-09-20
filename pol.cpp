#include<iostream>
using namespace std;
class Node {
    public:
        int coefficient;
        int power;
        Node* next;
        Node(int coeff, int pwr) {
            coefficient = coeff;
            power = pwr;
            next = nullptr;
        }    
};


class Polynomial {
    private:
        Node* head;
    public:  
    Polynomial() {
            head = nullptr;
        }  
        void pushBack(int coefficient, int power) {
            Node* newNode = new Node(coefficient, power);
            if(head == nullptr) {
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
        void pushFront(int coefficient, int power) {
            Node* newNode = new Node(coefficient, power);
            if(head == nullptr) {
                head = newNode;
                return;
            }
            else {
                newNode->next = head;
                head = newNode;
            }
        }

        void display() {
    Node* current = head;
    while(current != nullptr) {
        cout << current->coefficient << "x^" << current->power;
        if(current->next != nullptr)
            cout << " + ";
        current = current->next;
    }
    cout << endl;
}

};



int main() {
    Polynomial p;
    p.pushBack(2,2);
    p.pushBack(3,4);
    p.display();
    return 0;
}