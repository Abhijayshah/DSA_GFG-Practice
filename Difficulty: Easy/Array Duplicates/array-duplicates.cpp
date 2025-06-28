// User function template for C++

class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        unordered_map<int, int> freq;      // To store frequency of each element
        vector<int> ans;                   // To store final duplicates

        for (int num : arr) {             // Loop through each element
            freq[num]++;                  // Increment frequency count
        }

        for (auto it : freq) {             // Loop through frequency map
            if (it.second > 1) {          // If element occurs more than once
                ans.push_back(it.first);  // Add to result
            }
        }

        sort(ans.begin(), ans.end());     // Sort result (optional but usually expected)

        return ans;                       // Return final list
    }
};
