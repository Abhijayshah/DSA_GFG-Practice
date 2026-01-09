class Solution {
  public:
    string rearrangeString(string s) {

        vector<int> freq(26, 0);               // Frequency of characters

        for (char c : s) {                     // Count frequency
            freq[c - 'a']++;
        }

        // Max heap: pair<frequency, character>
        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push({freq[i], char('a' + i)});
            }
        }

        string result = "";
        pair<int, char> prev = {0, '#'};       // Previous used character

        while (!pq.empty()) {

            auto curr = pq.top();              // Most frequent character
            pq.pop();

            result.push_back(curr.second);     // Add character
            curr.first--;                      // Decrease frequency

            // Push previous back if it still has remaining frequency
            if (prev.first > 0) {
                pq.push(prev);
            }

            prev = curr;                       // Update previous
        }

        // If rearrangement not possible
        if (result.length() != s.length())
            return "";

        return result;
    }
};
