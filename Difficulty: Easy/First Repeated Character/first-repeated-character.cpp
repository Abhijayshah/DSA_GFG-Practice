class Solution {
  public:
    string firstRepChar(string s) {
        // Use a set to track characters we've seen
        unordered_set<char> seen;
        
        // Iterate through each character in the string
        for (char c : s) {
            // If we've seen this character before, it's our answer
            if (seen.find(c) != seen.end()) {
                return string(1, c);  // Convert char to string
            }
            // Otherwise, mark this character as seen
            seen.insert(c);
        }
        
        // No repeated character found
        return "-1";
    }
};