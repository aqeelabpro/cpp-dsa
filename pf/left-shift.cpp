#include<iostream>
using namespace std;

void left_shift_by_k_positions(int* arr, int n, int k) {
    if (n <= 0) return;
    int d = k % n;      

    for (int i = 0; i < d; i++) {
        int temp = arr[0];            
        for (int j = 0; j < n-1; j++) {
            arr[j] = arr[j + 1];      
        }
        arr[n - 1] = temp;            
    }
}

void print(int* arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;    
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 1;

    left_shift_by_k_positions(arr, n, k);
    print(arr,n);

    n = 5;
    k = 2;
    left_shift_by_k_positions(arr, n, k);
    print(arr,n);

    n = 5;
    k = 3;
    left_shift_by_k_positions(arr, n, k);
    print(arr,n);

    n = 5;
    k = 4;
    left_shift_by_k_positions(arr, n, k);
    print(arr,n);


    n = 5;
    k = 5;
    left_shift_by_k_positions(arr, n, k);
    print(arr,n);


    n = 5;
    k = 6;
    left_shift_by_k_positions(arr, n, k);
    print(arr,n);
}