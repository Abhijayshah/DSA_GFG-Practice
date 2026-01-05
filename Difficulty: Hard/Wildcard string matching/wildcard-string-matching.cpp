class Solution {
public:
    bool match(string wild, string pattern) {

        int n = wild.size();          // Length of wild string
        int m = pattern.size();       // Length of pattern string

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;              // Empty wild matches empty pattern

        // If pattern is empty, wild must be all '*'
        for (int i = 1; i <= n; i++) {
            if (wild[i - 1] == '*') {
                dp[i][0] = dp[i - 1][0];
            }
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // Case 1: Characters match or '?'
                if (wild[i - 1] == pattern[j - 1] || wild[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                // Case 2: '*'
                else if (wild[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }

                // Else remains false
            }
        }

        return dp[n][m];              // Final result
    }
};
