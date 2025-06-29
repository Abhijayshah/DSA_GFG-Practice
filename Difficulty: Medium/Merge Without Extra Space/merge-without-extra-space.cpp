class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size() , m = b.size();
        int i = n - 1;  // pointer at end of arr1
    int j = 0;      // pointer at start of arr2

    // Step 1: Swap out-of-order elements
    while (i >= 0 && j < m) {
        if (a[i] > b[j]) {
            swap(a[i], b[j]);
        }
        i--;
        j++;
    }

    // Step 2: Sort both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    }
};