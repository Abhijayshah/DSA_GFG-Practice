class Solution {
  public:
    long long int squaresDiff(int N) {
        // sum of squares formula
        long long sumSquares = 1LL * N * (N + 1) * (2 * N + 1) / 6;
        
        // sum of first N numbers formula
        long long sum = 1LL * N * (N + 1) / 2;
        
        // square of sum
        long long squareSum = sum * sum;
        
        // return absolute difference
        return llabs(sumSquares - squareSum);
    }
};
