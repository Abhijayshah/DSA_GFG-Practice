class Solution {
  public:
    int countMinReversals(string s) {

        int n = s.length();

        // If length is odd, cannot be balanced
        if (n % 2 != 0)
            return -1;

        int open = 0, close = 0;

        // Process the string
        for (char c : s) {
            if (c == '{') {
                open++;
            } else { // c == '}'
                if (open > 0) {
                    open--;   // matched with '{'
                } else {
                    close++;  // unmatched '}'
                }
            }
        }

        // Calculate minimum reversals
        int reversals = (open + 1) / 2 + (close + 1) / 2;
        return reversals;
    }
};
