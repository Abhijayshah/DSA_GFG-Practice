class Solution {
  public:
    string smallestWindow(string &s1, string &s2) {
        if (s1.length() < s2.length()) {
            return "";
        }
        
        unordered_map<char, int> s2_freq;
        for (char c : s2) {
            s2_freq[c]++;
        }
        
        unordered_map<char, int> window_freq;
        int left = 0, right = 0;
        int required = s2_freq.size();
        int formed = 0;
        
        int min_len = INT_MAX;
        int min_start = 0;
        
        while (right < s1.length()) {
            char c = s1[right];
            window_freq[c]++;
            
            if (s2_freq.count(c) && window_freq[c] == s2_freq[c]) {
                formed++;
            }
            
            while (left <= right && formed == required) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_start = left;
                }
                
                char left_char = s1[left];
                window_freq[left_char]--;
                if (s2_freq.count(left_char) && window_freq[left_char] < s2_freq[left_char]) {
                    formed--;
                }
                left++;
            }
            
            right++;
        }
        
        return min_len == INT_MAX ? "" : s1.substr(min_start, min_len);
    }
};