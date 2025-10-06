class Solution {
  public:
    int divisibleBy4(string N) {
        int len = N.length();

        // If the number has only one digit
        if (len == 1) {
            int num = N[len - 1] - '0';
            return (num % 4 == 0) ? 1 : 0;
        }

        // Extract last two digits as integer
        int lastTwo = (N[len - 2] - '0') * 10 + (N[len - 1] - '0');

        // Check divisibility by 4
        return (lastTwo % 4 == 0) ? 1 : 0;
    }
};
