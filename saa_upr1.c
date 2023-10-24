#include "stdio.h"

void sumDigitsInNumber(int number) {
    int sum = 0;
    do {
        sum += chislo % 10;
        chislo /= 10;
    } while (chislo != 0);
    printf("%d\n", sum);
}

void swapWithAddition(int a, int b) {
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a: %d, b: %d\n", a, b);
}

void countAdjacentDifferentSigns(int* arr) {
    int count = 0;
    for (int i = 0; i < ((sizeof(arr)/sizeof(int)) - 1); i++) {
        if ((arr[i] > 0 && arr[i + 1] < 0) || (arr[i] < 0 && arr[i + 1] > 0)) {
            count++;
        }
    }
    printf("%d", count);
}

static int last_number = 0;
void recurrentRowGetFirstBiggerThanHundred(int previous_number) {
    last_number = (2 * previous_number) + 10;
    if (last_number > 100) {
        printf("%d\n", last_number);
        return;
    } 
    recurrentRowGetFirstBiggerThanHundred(last_number);
}

int main() {
    int number = 12345;
    sumDigitsInNumber(number);
    
    int a = 1;
    int b = 2;
    printf("a: %d, b: %d\n", a, b);
    swapWithAddition(a, b);
 
    int arr[] = {1, -2, 3, -4, 5, -6, 7, 8, 9};
    countAdjacentDifferentSigns(arr);

    recurrentRowGetFirstBiggerThanHundred(2);

    return 0;
}