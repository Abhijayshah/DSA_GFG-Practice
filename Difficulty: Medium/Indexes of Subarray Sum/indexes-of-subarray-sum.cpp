class Solution {
  public:
    vector<int> subarraySum(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, right = 0;
        long long currentSum = 0;
        
        while (right < n) {
            // Add current element to the window
            currentSum += arr[right];
            
            // If sum exceeds, shrink from left
            while (currentSum > target && left <= right) {
                currentSum -= arr[left];
                left++;
            }
            
            // Check for exact match
            if (currentSum == target) {
                // Return 1-based indices
                return {left + 1, right + 1};
            }
            
            // Move right forward
            right++;
        }
        
        // No such subarray found
        return {-1};
    }
};
