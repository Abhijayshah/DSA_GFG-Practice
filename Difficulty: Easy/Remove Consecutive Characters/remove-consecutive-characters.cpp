class Solution {
  public:
    string removeConsecutiveCharacter(string& s) {

        string result = "";                  // Result string

        for (int i = 0; i < s.length(); i++) {

            // If result is empty OR current char is different
            if (result.empty() || result.back() != s[i]) {
                result.push_back(s[i]);      // Add character
            }
        }

        return result;                       // Return final string
    }
};
