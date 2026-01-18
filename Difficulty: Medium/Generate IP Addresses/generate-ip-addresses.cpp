class Solution {
public:
    vector<string> result;

    // Helper function for backtracking
    void backtrack(string &s, int index, int parts, string current) {

        // If 4 parts are formed and full string is used
        if (parts == 4 && index == s.size()) {
            // Remove last dot
            current.pop_back();
            result.push_back(current);
            return;
        }

        // If parts exceed 4 or string ends early
        if (parts >= 4)
            return;

        // Try segments of length 1 to 3
        for (int len = 1; len <= 3; len++) {

            if (index + len > s.size())
                break;

            string segment = s.substr(index, len);

            // Leading zero check
            if (segment.size() > 1 && segment[0] == '0')
                continue;

            int value = stoi(segment);
            if (value > 255)
                continue;

            // Recurse with chosen segment
            backtrack(s, index + len, parts + 1, current + segment + ".");
        }
    }

    vector<string> generateIp(string s) {

        result.clear();

        // Early pruning
        if (s.size() < 4 || s.size() > 12)
            return result;

        backtrack(s, 0, 0, "");

        return result;
    }
};
