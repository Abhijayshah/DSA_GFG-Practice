// User function Template for C++
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        // Initialize min_val and max_val to the first element of the array
        int min_val = arr[0], max_val = arr[0];
        
        // Traverse through the array
        for (int i = 1; i < arr.size(); i++) {
            // Update min and max values
            if (arr[i] < min_val) {
                min_val = arr[i];
            }
            if (arr[i] > max_val) {
                max_val = arr[i];
            }
        }
        
        // Return the pair of min and max values
        return {min_val, max_val};
    }
};
