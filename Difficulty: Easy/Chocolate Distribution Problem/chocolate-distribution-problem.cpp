class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // Sort the array to group similar values together
        sort(a.begin(), a.end());
        
        int n = a.size();
        int minDiff = INT_MAX;
        
        // Try all consecutive subarrays of length m
        // The difference will be a[i+m-1] - a[i] for each starting position i
        for (int i = 0; i <= n - m; i++) {
            int currentDiff = a[i + m - 1] - a[i];
            minDiff = min(minDiff, currentDiff);
        }
        
        return minDiff;
    }
};