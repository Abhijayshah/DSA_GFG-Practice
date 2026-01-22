// User function Template for C++
class Solution {
  public:
bool searchPattern(string& txt, string& pat) {
    int n = txt.size();
    int m = pat.size();

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && txt[i + j] == pat[j]) {
            j++;
        }
        if (j == m)
            return true;
    }
    return false;
}

};
