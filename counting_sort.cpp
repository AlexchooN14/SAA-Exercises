#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

void printArr(int* arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << "]" << endl;
}

int findMaxInArr(int * arr, int size) {
    int max = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}


void countingSort(int * arr, int size) {
    int maxVal = findMaxInArr(arr, size);
    int counts[maxVal + 1];
    memset(counts, 0, sizeof(counts)); 

    for (int i = 0; i < size; i++) {
        counts[arr[i]]++;
    }
    
    for (int i = 1; i <= maxVal; i++) {
        counts[i] += counts[i - 1];
    }
    
    int tempArr[size];
    for (int i = 0; i <= size; i++) {
        tempArr[counts[arr[i]] - 1] = arr[i];
        counts[arr[i]]--;
    }
    
    memcpy(arr, tempArr, size * sizeof(int));
}

int main()
{
    int arr[] = {1, 4, 1, 2, 7, 5, 2};
    printArr(arr, sizeof(arr) / sizeof(int));
    countingSort(arr, sizeof(arr) / sizeof(int));
    printArr(arr, sizeof(arr) / sizeof(int));
    
    return 0;
}
