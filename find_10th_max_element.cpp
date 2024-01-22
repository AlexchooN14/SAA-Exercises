#include <iostream>
#include <climits>
#include <cstring>
#include <vector>

#define N 20

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

int find10thLargestInMainDiagonal(int matrix[N][N]) {
    vector<int> v;
    for (int i = 0; i < N; i++) {
        v.push_back(matrix[i][i]);
    }

    int diagonalElements[v.size()];
    copy(v.begin(), v.end(), diagonalElements);
    
    if (v.size() >= 10) {
        countingSort(diagonalElements, v.size());
        printArr(diagonalElements, v.size());
        return diagonalElements[10];
    } else {
        cerr << "Matrix doesn't have 10 elements in the main diagonal.\n";
        return -1;
    }
}

int main()
{
    int matrix[N][N] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 21, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 82, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 99, 18, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 64, 17, 18, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0, 16, 17, 18, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 77, 15, 16, 17, 18, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 95, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 21, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 43, 13, 14, 15, 16, 17, 18, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 44, 14, 15, 16, 17, 18, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 26, 15, 16, 17, 18, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 99, 16, 17, 18, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 88, 17, 18, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 28, 18, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 34, 19, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 55, 20},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 47},
    };

    cout << find10thLargestInMainDiagonal(matrix) << endl;
    
    return 0;
}
