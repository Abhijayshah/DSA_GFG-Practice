class Solution {
public:
    vector<string> AllPossibleStrings(string s) {
        int n = s.length();
        vector<string> result;
        
        // Generate all possible subsequences using bit manipulation
        // Total subsequences = 2^n, but we skip empty subsequence (i = 0)
        for (int i = 1; i < (1 << n); i++) {
            string subsequence = "";
            
            // Check each bit position
            for (int j = 0; j < n; j++) {
                // If jth bit is set, include s[j] in subsequence
                if (i & (1 << j)) {
                    subsequence += s[j];
                }
            }
            
            result.push_back(subsequence);
        }
        
        // Sort the result lexicographically
        sort(result.begin(), result.end());
        return result;
    }
};

// Alternative: Backtracking approach
class SolutionBacktrack {
public:
    vector<string> AllPossibleStrings(string s) {
        vector<string> result;
        string current = "";
        
        backtrack(s, 0, current, result);
        
        // Sort the result lexicographically
        sort(result.begin(), result.end());
        return result;
    }
    
private:
    void backtrack(const string& s, int index, string& current, vector<string>& result) {
        // If we've processed all characters
        if (index == s.length()) {
            if (!current.empty()) {  // Only add non-empty subsequences
                result.push_back(current);
            }
            return;
        }
        
        // Choice 1: Don't include current character
        backtrack(s, index + 1, current, result);
        
        // Choice 2: Include current character
        current.push_back(s[index]);
        backtrack(s, index + 1, current, result);
        current.pop_back();  // Backtrack
    }
};

// Optimized: Generate in lexicographical order directly
class SolutionOptimized {
public:
    vector<string> AllPossibleStrings(string s) {
        vector<string> result;
        generateSubsequences(s, 0, "", result);
        return result;
    }
    
private:
    void generateSubsequences(const string& s, int index, string current, vector<string>& result) {
        // Add current subsequence if it's non-empty
        if (!current.empty()) {
            result.push_back(current);
        }
        
        // Generate subsequences starting from current index
        for (int i = index; i < s.length(); i++) {
            generateSubsequences(s, i + 1, current + s[i], result);
        }
    }
};

// Most efficient: Iterative approach building subsequences incrementally
class SolutionIterative {
public:
    vector<string> AllPossibleStrings(string s) {
        vector<string> result = {""};  // Start with empty string
        
        for (char c : s) {
            int size = result.size();
            // For each existing subsequence, create a new one by appending current character
            for (int i = 0; i < size; i++) {
                result.push_back(result[i] + c);
            }
        }
        
        // Remove empty string and sort
        result.erase(result.begin());  // Remove empty string
        sort(result.begin(), result.end());
        return result;
    }
};