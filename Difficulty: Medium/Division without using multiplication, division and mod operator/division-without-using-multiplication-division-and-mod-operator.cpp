class Solution {
  public:
    long long divide(long long dividend, long long divisor) {
        
        // Handle division by zero (optional safety)
        if (divisor == 0)
            return INT_MAX;
        
        // Handle overflow case
        if (dividend == LLONG_MIN && divisor == -1)
            return INT_MAX;
        
        // Determine sign of result
        bool negative = (dividend < 0) ^ (divisor < 0);
        
        // Convert both numbers to positive
        long long a = llabs(dividend);
        long long b = llabs(divisor);
        
        long long quotient = 0; // Store result
        
        // Perform division using bit manipulation
        while (a >= b) {
            
            long long temp = b;     // Temporary divisor multiple
            long long multiple = 1; // Corresponding multiple
            
            // Double temp until it exceeds a
            while ((temp << 1) <= a) {
                temp <<= 1;       // Multiply temp by 2
                multiple <<= 1;   // Multiply multiple by 2
            }
            
            a -= temp;          // Subtract largest possible multiple
            quotient += multiple; // Add to quotient
        }
        
        // Apply sign
        if (negative)
            quotient = -quotient;
        
        // Clamp result within 32-bit signed integer range
        if (quotient > INT_MAX)
            return INT_MAX;
        if (quotient < INT_MIN)
            return INT_MIN;
        
        return quotient; // Return final quotient
    }
};