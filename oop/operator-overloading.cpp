#include<iostream>
using namespace std;

class Complex {
    private:
        int real;
        int imag;
    public:
        Complex(int real, int imag) : real(real), imag(imag) {}
        Complex& operator+(Complex other) {
            this->real+=other.real;
            this->imag+=other.imag;
            return *this;
        }
        int getReal() {
            return real;
        }    

        int getImag() {
            return imag;
        }    
};

int main() {
    Complex o1(5,5);
    Complex o2(-2,-2);
    Complex o3(1,1);
    Complex o4 = o1+o2+o3;
    cout << o4.getReal();
}