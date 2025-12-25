class Solution {
  public:
    int getLPSLength(string &s) {

        int n = s.size();

        // LPS array to store longest prefix-suffix values
        vector<int> lps(n, 0);

        int len = 0;  // length of previous longest prefix-suffix
        int i = 1;    // start from second character

        while (i < n) {

            // If characters match, extend prefix-suffix
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                // If mismatch and len is not zero
                if (len != 0) {
                    len = lps[len - 1];  // fallback
                }
                else {
                    // No prefix-suffix possible
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Last value of LPS array is the answer
        return lps[n - 1];
    }
};
