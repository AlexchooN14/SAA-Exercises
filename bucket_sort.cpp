#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void printArr(double* arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << "]" << endl;
}

void sortBucket(vector<double>& bucket) {
    // 3 2 1 5
    for (int i = 1; i < bucket.size(); i++) {
        double key = bucket[i];
        int j = i - 1;
        
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        
        bucket[j + 1] = key;
    }
}

void bucketSort(double * arr, int size) {
    vector<vector<double>> buckets(size);
    for (int i = 0; i < size; i++) {
        int absVal = *(arr + i) * 10;
        buckets[absVal].push_back(*(arr + i));
    }
    vector<double> flattenedVector;
    for (auto &bucket : buckets) {
        sortBucket(bucket);
        flattenedVector.insert(flattenedVector.end(), bucket.begin(), bucket.end());
    }

    memcpy(arr, flattenedVector.data(), size * sizeof(double));
}

int main()
{
    double arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    printArr(arr, sizeof(arr) / sizeof(double));
    bucketSort(arr, sizeof(arr) / sizeof(double));
    printArr(arr, sizeof(arr) / sizeof(double));
    
    return 0;
}
