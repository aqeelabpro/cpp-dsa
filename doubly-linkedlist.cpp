#include<iostream>
using namespace std;
class Node {
    public:    
        int data;
        Node* next;
        Node* prev;
        Node(int data) {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        Node* tail;
    public:    
        static int size;
        LinkedList() {
            this->head = this->tail =  nullptr;
        }
};
int main() {

}