#include<iostream>
using namespace std;

string toSuperscript(int n) {
    string s = "";
    string digits = to_string(n);
    for(char c : digits) {
        switch(c) {
            case '0': s += "\u2070"; break;
            case '1': s += "\u00B9"; break;
            case '2': s += "\u00B2"; break;
            case '3': s += "\u00B3"; break;
            case '4': s += "\u2074"; break;
            case '5': s += "\u2075"; break;
            case '6': s += "\u2076"; break;
            case '7': s += "\u2077"; break;
            case '8': s += "\u2078"; break;
            case '9': s += "\u2079"; break;
        }
    }
    return s;
}

class Node {
    public:
        int coeff;
        int power;
        Node* next;
        Node(int c, int p) {
            coeff  = c;
            power = p;
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
        Polynomial(int coeff, int power) {
            head = nullptr;
            addPolynomialToFront(coeff, power);
        }
        
        void addPolynomialToFront(int coeff, int power) {
            Node* temp = new Node(coeff, power);
            if(head == nullptr) {
                head = temp;
            }
            else {
                Node* current = head;
                while(current -> next != nullptr) {
                    current = current->next;
                }
                current->next = temp;
            }
        }
        void display() {
            cout << "Polynomials: ";
            Node* current = head;
            if(current == nullptr) {
                cout << "Empty Polynomial";
                return;
            }
            else {
                while(current != nullptr) {
                    cout << current->coeff << "x" << toSuperscript(current->power) << " -> ";
                    current = current->next;
                }
                cout << "NULL";
            }
        }
};


int main() {
    Polynomial p;
    p.addPolynomialToFront(8,3);
    p.addPolynomialToFront(2,2);
    p.display();
}