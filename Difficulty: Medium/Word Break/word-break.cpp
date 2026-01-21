class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dictionary) {
        int n = s.length();
        
        // Convert dictionary to unordered_set for O(1) lookup
        unordered_set<string> wordSet(dictionary.begin(), dictionary.end());
        
        // Find max word length to limit search range
        int maxLen = 0;
        for (const string& word : dictionary) {
            maxLen = max(maxLen, (int)word.length());
        }
        
        // dp[i] = true if s[0...i-1] can be segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; i++) {
            // Only check words of valid length
            for (int j = max(0, i - maxLen); j < i; j++) {
                if (dp[j]) {
                    // Use string_view or direct comparison to avoid substring creation
                    string temp = s.substr(j, i - j);
                    if (wordSet.count(temp)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
    }
};