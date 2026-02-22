class Solution {
  public:
    
    int countSetBits(int n) {
        
        int count = 0; // Store total set bits
        
        while (n > 0) {
            
            // Find largest power of 2 less than or equal to n
            int x = log2(n); 
            
            // Number of set bits from 1 to (2^x - 1)
            count += x * (1 << (x - 1));
            
            // MSB contribution from 2^x to n
            count += (n - (1 << x) + 1);
            
            // Reduce n to remainder after removing highest power of 2
            n = n - (1 << x);
        }
        
        return count; // Return total set bits
    }
};