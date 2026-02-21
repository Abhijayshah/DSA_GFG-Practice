class Solution {
  public:
    int countBitsFlip(int a, int b) {
        
        int xorResult = a ^ b; // XOR gives 1 where bits differ
        
        int count = 0; // Store number of bits to flip
        
        // Count set bits using Brian Kernighan’s Algorithm
        while (xorResult > 0) {
            
            xorResult = xorResult & (xorResult - 1);
            // Removes the rightmost set bit
            
            count++; // Increment flip count
        }
        
        return count; // Return total flips required
    }
};