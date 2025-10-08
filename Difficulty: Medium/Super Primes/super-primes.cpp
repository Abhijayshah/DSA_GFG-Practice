class Solution {
  public:
    int superPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;

        // Sieve of Eratosthenes
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        int count = 0;
        for (int i = 5; i <= n; i++) { // start from 5 (smallest super prime)
            if (isPrime[i] && isPrime[i - 2])
                count++;
        }

        return count;
    }
};
