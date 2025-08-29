class Solution {
  public:
    // Function to build LPS array for KMP
    vector<int> buildLPS(string &pat) {
        int m = pat.size();
        vector<int> lps(m, 0);
        int len = 0;  // length of previous longest prefix suffix
        int i = 1;
        
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    // KMP string matching
    bool kmpSearch(string &text, string &pat) {
        int n = text.size();
        int m = pat.size();
        vector<int> lps = buildLPS(pat);
        
        int i = 0, j = 0;  // i->text, j->pattern
        while (i < n) {
            if (text[i] == pat[j]) {
                i++; j++;
                if (j == m) return true;  // found
            } else {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return false;
    }

    bool areRotations(string &s1, string &s2) {
        if (s1.size() != s2.size()) return false;
        
        string temp = s1 + s1;
        
        // KMP substring search instead of find()
        return kmpSearch(temp, s2);
    }
};
