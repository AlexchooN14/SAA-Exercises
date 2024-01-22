#include <iostream>

using namespace std;


void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = *(arr + i);
        int j = i - 1;
        
        while (j >= 0 && *(arr + j) > key) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        
        *(arr + j + 1) = key;
    }
    
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {
    int arr[7] = {7, 8, 5, 2, 4, 6, 3};

    insertionSort(arr, 7);

    return 0;
}