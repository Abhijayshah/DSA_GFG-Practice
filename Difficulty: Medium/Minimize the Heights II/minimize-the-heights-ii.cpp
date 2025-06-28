// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;

        sort(arr.begin(), arr.end());

        // Initial difference without any changes
        int ans = arr[n - 1] - arr[0];

        int smallest, largest;

        for (int i = 0; i < n - 1; i++) {
            int minEle = min(arr[0] + k, arr[i + 1] - k);
            int maxEle = max(arr[i] + k, arr[n - 1] - k);

            // Skip if new minimum becomes negative
            if (minEle < 0) continue;

            ans = min(ans, maxEle - minEle);
        }

        return ans;
    }
};
