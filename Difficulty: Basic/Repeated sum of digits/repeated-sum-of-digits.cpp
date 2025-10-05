class Solution {
public:
    int repeatedSumOfDigits(int N) {
        if (N == 0) return 0;
        return 1 + (N - 1) % 9;
    }
};
