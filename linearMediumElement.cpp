#include <iostream>
#include <climits>

#define N 4

using namespace std;

// int matrix1[N][N] = {
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 9}
// };

int matrix2[N][N] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};

int findMediumElementSecondaryDiagonal(int* arr) {
    int secondaryDiagonal[N];
    int median, mediumElement;

    for (int i = 0; i < N; i++) {
        int j = N - i - 1;
        secondaryDiagonal[i] = *(arr + i * N + j);
    }

    if (N % 2 == 0) {
        int mid1 = secondaryDiagonal[N / 2 - 1];
        int mid2 = secondaryDiagonal[N / 2];
        median = (mid1 + mid2) / 2;
    } else {
        median = secondaryDiagonal[N / 2];
    }

    int diff = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (diff > abs(median - *(secondaryDiagonal + i))) {
            diff = abs(median - *(secondaryDiagonal + i));
            mediumElement = *(secondaryDiagonal + i);
        }
    }
    return mediumElement;
}

int main() {
    cout << findMediumElementSecondaryDiagonal(&matrix2[0][0]) << endl;

    return 0;
}