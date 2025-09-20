#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = this->prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = tail = nullptr;
    }
    void insertAtIndex(int data, int index)
    {
        Node *newNode = new Node(data);
        // Case 1: Insert at beginning
        if (index == 0)
        {
            if (head == nullptr)
            { // empty list
                head = tail = newNode;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            return;
        }

        Node *current = head;
        int count = 0;

        while (current != nullptr && count < index - 1)
        {
            current = current->next;
            count++;
        }

        if (current == nullptr)
        {
            cout << "Index Out Of Bounds\n";
            delete newNode;
            return;
        }

        // Case 2: Insert at the end
        if (current->next == nullptr)
        {
            current->next = newNode;
            newNode->prev = current;
            tail = newNode;
            return;
        }

        // Case 3: Insert in middle
        newNode->next = current->next;
        current->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    }

    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL";
    }
};

int main()
{

    DoublyLinkedList dll;
    dll.insertAtIndex(10, 0);
    dll.insertAtIndex(20, 1);
    dll.insertAtIndex(30, 2);
    dll.display();

    return 0;
}