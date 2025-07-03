class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        
        set<vector<int>> uniquePairs;
        
        for (auto& it : freq) {
            int num = it.first;
            
            // Handle zero separately
            if (num == 0 && freq[0] > 1) {
                uniquePairs.insert({0, 0});
            }
            else if (num > 0 && freq.find(-num) != freq.end()) {
                uniquePairs.insert({-num, num});
            }
        }
        
        vector<vector<int>> res(uniquePairs.begin(), uniquePairs.end());
        sort(res.begin(), res.end()); // ensure final sorted order
        
        return res;
    }
};
