class Solution {
  public:
    int isPowerOfAnother(int X, int Y) {
        if (X == 1) {
            // 1^any = 1, so only true if Y == 1
            return (Y == 1);
        }
        
        while (Y % X == 0) {
            Y /= X;
        }
        
        return (Y == 1);
    }
};
