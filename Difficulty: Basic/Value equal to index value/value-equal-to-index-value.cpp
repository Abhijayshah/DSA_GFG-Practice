// User function template for C++
class Solution {
  public:
    // Function to find elements in the array that are equal to their index.
    vector<int> valueEqualToIndex(vector<int>& arr) {
        vector<int> result;
        
        // Iterate through the array
        for (int i = 0; i < arr.size(); i++) {
            // Check if value equals 1-based index
            if (arr[i] == i + 1) {
                result.push_back(i + 1); // Store 1-based index
            }
        }
        
        return result;
    }
};