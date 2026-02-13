class Solution {
public:
    void sortBySetBitCount(int arr[], int n) {
        stable_sort(arr, arr + n, [](int a, int b) { // Stable sort maintains original order for equal elements
            return __builtin_popcount(a) > __builtin_popcount(b); // Compare set bit counts in descending order
        });
    }
};