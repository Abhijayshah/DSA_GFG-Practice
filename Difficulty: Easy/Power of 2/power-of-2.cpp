class Solution {
  public:
    bool isPowerofTwo(int n) {

        // Power of 2 must be positive
        if (n <= 0) return false;

        // Check if only one bit is set
        return (n & (n - 1)) == 0;
    }
};
