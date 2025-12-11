class Solution {
public:

    int countMin(string str) {
        int n = str.length();
        string rev = str;
        reverse(rev.begin(), rev.end());               // Reverse the string
        
        // DP table for LCS
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (str[i - 1] == rev[j - 1])           // If characters match
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                
                else                                     // If not match, take max of two options
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int LPS = dp[n][n];                              // LPS = LCS of str and reverse(str)
        return n - LPS;                                  // Minimum insertions
    }
};
