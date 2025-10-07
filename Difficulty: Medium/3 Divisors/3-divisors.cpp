#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> threeDivisors(vector<long long> query, int q) {
        const int MAX = 1e6;
        vector<bool> isPrime(MAX + 1, true);
        isPrime[0] = isPrime[1] = false;

        // Sieve of Eratosthenes
        for (int i = 2; i * i <= MAX; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= MAX; j += i)
                    isPrime[j] = false;
            }
        }

        // Store primes
        vector<long long> primes;
        for (int i = 2; i <= MAX; i++) {
            if (isPrime[i])
                primes.push_back(i);
        }

        vector<int> ans;
        for (int i = 0; i < q; i++) {
            long long n = query[i];
            long long limit = sqrt(n);

            // Count primes ≤ sqrt(n)
            int count = upper_bound(primes.begin(), primes.end(), limit) - primes.begin();
            ans.push_back(count);
        }

        return ans;
    }
};
