class Solution {
  public:
    int solveWordWrap(vector<int> arr, int k) {
        int n = arr.size();
        const int INF = 1e9;

        // dp[i] = minimum cost to arrange words from i to n-1
        vector<int> dp(n + 1, INF);
        dp[n] = 0;  // No words left → no cost

        // Fill DP from back
        for (int i = n - 1; i >= 0; i--) {
            int lineLength = 0;

            for (int j = i; j < n; j++) {
                lineLength += arr[j];

                // Add space between words
                if (j > i) lineLength++;

                // If exceeds line width, stop
                if (lineLength > k) break;

                int extraSpaces = k - lineLength;
                int cost;

                // Last line has zero cost
                if (j == n - 1)
                    cost = 0;
                else
                    cost = extraSpaces * extraSpaces;

                dp[i] = min(dp[i], cost + dp[j + 1]);
            }
        }

        return dp[0];
    }
};
