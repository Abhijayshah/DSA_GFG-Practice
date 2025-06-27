// User function template for C++

class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp; // temporary array to store the result

        // Step 1: Add all positive elements to temp
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                temp.push_back(arr[i]);
            }
        }

        // Step 2: Add all negative elements to temp
        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                temp.push_back(arr[i]);
            }
        }

        // Step 3: Copy temp array back to original array
        for (int i = 0; i < n; i++) {
            arr[i] = temp[i];
        }
    }
};
