class Solution {
  public:
    int powMod(int x, int n, int M) {
        long long result = 1;
        long long base = x % M;  // Handle if x > M

        while (n > 0) {
            if (n % 2 == 1) {
                result = (result * base) % M;  // Multiply when n is odd
            }
            base = (base * base) % M;  // Square the base
            n = n / 2;                 // Divide n by 2
        }
        
        return (int)(result % M);
    }
};
