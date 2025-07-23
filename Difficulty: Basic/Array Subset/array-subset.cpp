#include <vector>
#include <unordered_map>

class Solution {
public:
    // Function to check if b is a subset of a
    bool isSubset(std::vector<int> &a, std::vector<int> &b) {
        // Create a hash map to store frequencies of elements in array 'a'
        std::unordered_map<int, int> freq_a;

        // Populate the frequency map for array 'a'
        for (int x : a) {
            freq_a[x]++;
        }

        // Iterate through array 'b' and check if its elements are present in 'a'
        for (int x : b) {
            // If the element x is not found in freq_a, or its count is 0 (meaning
            // all available occurrences in 'a' have been "used" by 'b' already),
            // then b is not a subset of a.
            if (freq_a.find(x) == freq_a.end() || freq_a[x] == 0) {
                return false;
            }
            // If found, decrement its count in freq_a as we've matched one occurrence
            freq_a[x]--;
        }

        // If we reach here, it means all elements in 'b' were found in 'a'
        // with sufficient frequencies.
        return true;
    }
};