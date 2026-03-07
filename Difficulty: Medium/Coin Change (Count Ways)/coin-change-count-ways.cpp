class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        
        int n = coins.size(); // Number of coin types
        
        // DP array where dp[i] = number of ways to make sum i
        vector<long long> dp(sum + 1, 0);
        
        dp[0] = 1; 
        // Base case: There is 1 way to make sum 0 (choose nothing)
        
        // Process each coin
        for (int coin : coins) {
            
            // Update ways for sums that can include this coin
            for (int i = coin; i <= sum; i++) {
                
                dp[i] += dp[i - coin];
                // Add ways using this coin
            }
        }
        
        return dp[sum]; // Total ways to make target sum
    }
};