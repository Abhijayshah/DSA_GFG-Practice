class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // Edge case: if there are less packets than students
        if (m == 0 || a.size() < m) return 0;

        // Step 1: Sort the array
        sort(a.begin(), a.end());

        // Step 2: Initialize min_diff to a large value
        int min_diff = INT_MAX;

        // Step 3: Traverse through all subarrays of size m
        for (int i = 0; i + m - 1 < a.size(); i++) {
            int diff = a[i + m - 1] - a[i];
            min_diff = min(min_diff, diff);
        }

        return min_diff;
    }
};
