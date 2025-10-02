class Solution {
  public:
    vector<int> rabinKarp(string &text, string &pattern) {
        vector<int> result;
        int n = text.size();
        int m = pattern.size();
        if (m > n) return result;

        // Base for polynomial rolling hash and a large prime modulus
        const int base = 256;      // number of characters in charset
        const int mod  = 1e9 + 7;  // large prime

        long long patHash = 0, txtHash = 0, power = 1;

        // Precompute base^(m-1) % mod
        for (int i = 0; i < m - 1; i++) {
            power = (power * base) % mod;
        }

        // Compute initial hash for pattern and first window of text
        for (int i = 0; i < m; i++) {
            patHash = (patHash * base + pattern[i]) % mod;
            txtHash = (txtHash * base + text[i]) % mod;
        }

        // Slide over text
        for (int i = 0; i <= n - m; i++) {
            // If hash matches, verify the substring
            if (patHash == txtHash) {
                if (text.substr(i, m) == pattern) {
                    result.push_back(i);
                }
            }

            // Compute hash for next window
            if (i < n - m) {
                txtHash = (txtHash - text[i] * power % mod + mod) % mod;
                txtHash = (txtHash * base + text[i + m]) % mod;
            }
        }

        return result;
    }
};
