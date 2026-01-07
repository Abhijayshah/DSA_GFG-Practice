// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        unordered_map<string, vector<string>> mp;
        
        for(string word : arr){
            string key = word;
            sort(key.begin(), key.end());
            
            mp[key].push_back(word);
            
        }
        vector<vector<string>> result;
        
        for (auto &it : mp){
            result.push_back(it.second);
            
        }
        
        return result;
        
    }
};
