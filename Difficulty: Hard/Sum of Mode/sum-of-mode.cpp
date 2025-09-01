#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> freq; // element -> frequency
        map<int,set<int>> freqBuckets; // frequency -> set of elements
        int maxFreq = 0, sum = 0;

        auto add = [&](int x) {
            int oldFreq = freq[x];
            int newFreq = ++freq[x];

            if (oldFreq > 0) {
                freqBuckets[oldFreq].erase(x);
                if (freqBuckets[oldFreq].empty()) {
                    freqBuckets.erase(oldFreq);
                }
            }
            freqBuckets[newFreq].insert(x);
            maxFreq = max(maxFreq, newFreq);
        };

        auto remove = [&](int x) {
            int oldFreq = freq[x];
            int newFreq = --freq[x];

            freqBuckets[oldFreq].erase(x);
            if (freqBuckets[oldFreq].empty()) {
                freqBuckets.erase(oldFreq);
                if (oldFreq == maxFreq) {
                    maxFreq--;
                }
            }
            if (newFreq > 0) {
                freqBuckets[newFreq].insert(x);
            }
        };

        // Initialize first window
        for (int i = 0; i < k; i++) {
            add(arr[i]);
        }
        sum += *freqBuckets[maxFreq].begin(); // smallest element among maxFreq

        // Process rest windows
        for (int i = k; i < n; i++) {
            add(arr[i]);
            remove(arr[i-k]);
            sum += *freqBuckets[maxFreq].begin();
        }

        return sum;
    }
};
