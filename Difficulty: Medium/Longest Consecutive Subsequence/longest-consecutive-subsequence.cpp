#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        int longest = 0;

        for (int num : arr) {
            // Only start counting if this number is the start of a sequence
            if (s.find(num - 1) == s.end()) {
                int currentNum = num;
                int count = 1;

                while (s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};
