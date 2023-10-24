#include "stdio.h"
#include <stdlib.h>

void multiplicationOfAjacentBiggerThan120(int* arr, int size) {
    int multiply_sum = 1;
    for (int i = 0; i < size - 1; i++) {
       ((arr[i] + arr[i + 1]) < 120) ? (multiply_sum *= (arr[i] * arr[i + 1])) : 0;
    }
    printf("%d\n", multiply_sum);
}

void numberOfAjacentGroups(int* arr, int size) {
    int last_element = 0;
    int groups = 0;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            if (last_element != arr[i]) {
                last_element = arr[i];
                groups++;
            }
        } else last_element = 0;
    }
    printf("%d\n", groups);
}

void getPerimeterSum2DArray(int* arr, int rows, int columns) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if ((i == 0 || i == rows - 1) || (j == 0 || j == columns - 1)) { // First row
                sum += *(arr + i*columns + j);
            } 
        }
    }
    printf("%d\n", sum);
}

int* exercise16(int* arr, int rows, int columns) {
    if (rows != columns) return NULL;
    int size_return_arr = 1 + rows + 1;
    int* return_arr = calloc(size_return_arr, sizeof(int));

    for (int i = 0; i < rows; i++) {
        return_arr[0] += *(arr + i * rows + i);
        for (int j = 0; j < columns; j++) {
            return_arr[i + 1] += *(arr + i * rows + j);
            if (i > 0 && j < i && *(arr + i * rows + j) < i + j) {
                return_arr[size_return_arr - 1]++;
            }
        }
    }
    
    return return_arr;
}

void exercise19(int* arr, int rows, int columns) {
    if (rows != columns) return;
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += *(arr + i * rows + (columns - i - 1));
    }
    printf("%d\n", sum);
}

int main() {
    int arr[] = {1, 2, 2, 3, 2, 2, 2, 3, 3, 3};
    int arr2d[][4] = {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
    };

    // multiplicationOfAjacentBiggerThan120(arr, sizeof(arr)/sizeof(int));
    // numberOfAjacentGroups(arr, sizeof(arr)/sizeof(int));
    // getPerimeterSum2DArray(arr2d[0], 4, 4);
    // exercise19(arr2d[0], 4, 4);

    // int* result_arr = exercise16(arr2d[0], 4, 4);

    // for (int i = 0; i < 6; i++) {  // Printing loop
    //     printf("%d\n", result_arr[i]);
    // }
    // free(result_arr);

    return 0;
}