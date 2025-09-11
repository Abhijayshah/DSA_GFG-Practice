class Solution {
  public:
    bool armstrongNumber(int n) {
        int original = n;   // store the number
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;       // get last digit
            sum += digit * digit * digit;  // add cube of digit
            n /= 10;                  // remove last digit
        }

        return sum == original;  // check if Armstrong or not
    }
};
