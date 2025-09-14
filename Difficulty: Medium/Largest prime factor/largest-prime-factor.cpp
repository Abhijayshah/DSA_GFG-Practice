class Solution {
  public:
    int largestPrimeFactor(int n) {
        int largest = -1;

        // Step 1: Divide out factor 2
        while (n % 2 == 0) {
            largest = 2;
            n /= 2;
        }

        // Step 2: Divide out odd factors
        for (int i = 3; i * 1LL * i <= n; i += 2) {
            while (n % i == 0) {
                largest = i;
                n /= i;
            }
        }

        // Step 3: If n > 2, then n is prime
        if (n > 2)
            largest = n;

        return largest;
    }
};
