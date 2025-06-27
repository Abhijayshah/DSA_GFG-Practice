// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return; // edge case: empty array

        int last = arr[n - 1]; // Step 1: store the last element

        // Step 2: Shift all elements one step to the right
        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        // Step 3: Place the last element at the front
        arr[0] = last;
    }
};
