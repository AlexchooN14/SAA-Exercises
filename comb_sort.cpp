#include <iostream>

using namespace std;

void printArr(int* arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << "]" << endl;
}

void combSort(int * arr, int size) {
    int iterations = 0;
    int gap = size;
    bool swapped = true;

    while (gap > 1 || swapped) {
        gap /= 1.3;
        
        if (gap < 1) gap = 1;
        
        swapped = false;

        for (int i = 0; i + gap < size; i++) {
            iterations++;
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
    cout << "iterations: " << iterations << endl;
}

int main()
{
    int arr[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    printArr(arr, sizeof(arr) / sizeof(int));
    combSort(arr, sizeof(arr) / sizeof(int));
    printArr(arr, sizeof(arr) / sizeof(int));
    
    return 0;
}
