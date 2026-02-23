class Solution {
  public:
    int findPosition(int n) {
        
        // If n is 0, no set bits
        if (n == 0)
            return -1;
        
        // Check if n has more than one set bit
        // A power of 2 has exactly one set bit
        if ((n & (n - 1)) != 0)
            return -1; // More than one set bit
        
        int position = 1; // Start counting from LSB (position = 1)
        
        // Shift right until we find the set bit
        while ((n & 1) == 0) {
            n = n >> 1;   // Right shift by 1
            position++;   // Increase position count
        }
        
        return position; // Return position of the only set bit
    }
};