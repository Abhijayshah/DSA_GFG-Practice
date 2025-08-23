#include <string>
#include <vector>
#include <algorithm>

// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        // Handle empty array case
        if (arr.empty()) {
            return "";
        }

        // Iterate through characters of the first string
        for (int i = 0; i < arr[0].length(); ++i) {
            char currentChar = arr[0][i];

            // Compare this character with the character at the same
            // position in all other strings
            for (int j = 1; j < arr.size(); ++j) {
                // If we are out of bounds for the current string OR
                // the characters don't match, we have found the LCP.
                if (i >= arr[j].length() || arr[j][i] != currentChar) {
                    return arr[0].substr(0, i);
                }
            }
        }

        // If the loop completes, the entire first string is the common prefix
        return arr[0];
    }
};