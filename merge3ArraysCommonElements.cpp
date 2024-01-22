#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
vector<int> arr2 = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
vector<int> arr3 = {9, 10, 11, 12, 13, 14, 15, 16, 17, 18};


vector<int> mergeCommonElementsInArr(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
    unordered_set<int> set1(arr1.begin(), arr1.end());
    unordered_set<int> set2(arr2.begin(), arr2.end());
    vector<int> D;

    for (int el : arr3) {
        if (set1.count(el) && set2.count(el)) {
            D.push_back(el);
            set1.erase(el);
            set2.erase(el);
        }
    }

    return D;
}


int main() {
    vector<int> D = mergeCommonElementsInArr(arr1, arr2, arr3);
    for (int element : D) {
        cout << element << " ";
    }

    return 0;
}