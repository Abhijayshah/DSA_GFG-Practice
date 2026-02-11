class Solution {
  public:
    int floorSqrt(int n) {
        
        int low = 1; // Starting point of search range
        int high = n; // Ending point of search range
        
        int ans = 0; // Variable to store final floor sqrt
        
        while (low <= high) { // Continue binary search
            
            int mid = low + (high - low) / 2; // Find middle safely
            
            // Use long long to prevent overflow
            long long square = (long long)mid * mid; 
            
            if (square == n) {
                // If perfect square found
                return mid;
            }
            else if (square < n) {
                // If mid^2 is less than n,
                // store mid as possible answer
                ans = mid;
                low = mid + 1; // Search right half
            }
            else {
                // If mid^2 is greater than n,
                // search left half
                high = mid - 1;
            }
        }
        
        return ans; // Return floor value
    }
};
