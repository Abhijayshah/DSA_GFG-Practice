// User function Template for C++

class Solution {
  public:
    string reverseString(string& s) {
        int n = s.size();
        int i = 0, j = n - 1;
        
        // Two-pointer approach
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        
        return s;
    }
};
