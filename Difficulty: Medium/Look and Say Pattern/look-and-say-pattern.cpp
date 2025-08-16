class Solution {
public:
    string countAndSay(int n) {
        // Base case: first row is "1"
        string result = "1";
        
        // Generate each subsequent row
        for (int i = 1; i < n; i++) {
            string nextResult = "";
            int j = 0;
            
            // Process the current result string
            while (j < result.length()) {
                char currentDigit = result[j];
                int count = 1;
                
                // Count consecutive occurrences of the same digit
                while (j + count < result.length() && result[j + count] == currentDigit) {
                    count++;
                }
                
                // Append count + digit to the next result
                nextResult += to_string(count) + currentDigit;
                
                // Move to the next group
                j += count;
            }
            
            result = nextResult;
        }
        
        return result;
    }
};

// Alternative cleaner implementation
class Solution2 {
public:
    string countAndSay(int n) {
        string result = "1";
        
        for (int i = 1; i < n; i++) {
            string temp = "";
            
            for (int j = 0; j < result.length(); ) {
                char digit = result[j];
                int count = 0;
                
                // Count consecutive identical digits
                while (j < result.length() && result[j] == digit) {
                    count++;
                    j++;
                }
                
                // Add count and digit to temp string
                temp += to_string(count) + digit;
            }
            
            result = temp;
        }
        
        return result;
    }
};