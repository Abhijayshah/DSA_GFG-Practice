class Solution {
public:
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
        int totalSum = 0, leftSum = 0;

        // Step 1: Calculate total sum
        for (int num : arr) totalSum += num;

        // Step 2: Traverse and check
        for (int i = 0; i < n; i++) {
            totalSum -= arr[i];  // now totalSum is the right sum

            if (leftSum == totalSum) return i;  // equilibrium found

            leftSum += arr[i];  // update left sum
        }

        return -1;  // no equilibrium point
    }
};
