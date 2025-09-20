#include<iostream>
using namespace std;


int main() {

    int arr[5] = {5,4,3,2,1};
    int n = 5;
    int minIndex;
    for(int i = 0; i < n - 1; i++) {
        minIndex  = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}