#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxValue(vector<int> &arr) {
        const long long MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());
        long long res = 0;

        for (long long i = 0; i < arr.size(); i++) {
            res = (res + (arr[i] * i) % MOD) % MOD;
        }

        return (int)res;
    }
};
