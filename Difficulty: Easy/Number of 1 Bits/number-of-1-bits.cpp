class Solution {
  public:
    int setBits(int n) {
        
        int count = 0; // Variable to store number of set bits
        
        // Brian Kernighan’s Algorithm
        while (n > 0) { 
            
            n = n & (n - 1); 
            // This operation removes the rightmost set bit from n
            
            count++; 
            // Increment count for each removed set bit
        }
        
        return count; // Return total number of set bits
    }
};
