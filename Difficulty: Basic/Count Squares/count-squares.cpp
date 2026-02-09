class Solution {
  public:
    int countSquares(int n) {
        if (n <= 1) return 0; // If n is 1 or less, no perfect squares less than n
        
        int count = sqrt(n - 1); // Find square root of (n-1) to get count of squares less than n
        
        return count; // Return the count
    }
};