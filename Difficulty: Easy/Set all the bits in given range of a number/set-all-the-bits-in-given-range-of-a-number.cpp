class Solution {
  public:
    int setAllRangeBits(int N, int L, int R) {

        // Step 1: Create a mask with (R-L+1) bits set to 1
        int mask = (1 << (R - L + 1)) - 1;

        // Step 2: Shift mask to align with L position
        mask = mask << (L - 1);

        // Step 3: Set bits in N using OR
        N = N | mask;

        // Step 4: Return the result
        return N;
    }
};
