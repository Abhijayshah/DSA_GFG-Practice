class Solution {
  public:
    vector<string> AllPossibleStrings(string s) {
        int n = s.size();
        vector<string> result;
        
        // Generate all subsets using bitmasking
        for (int mask = 1; mask < (1 << n); mask++) {  // start from 1 to avoid empty subset
            string subseq = "";
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subseq.push_back(s[i]);
                }
            }
            result.push_back(subseq);
        }
        
        // Sort lexicographically
        sort(result.begin(), result.end());
        
        return result;
    }
};
