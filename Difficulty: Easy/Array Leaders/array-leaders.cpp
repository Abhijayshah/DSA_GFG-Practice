class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> result;
        int maxFromRight = INT_MIN;

        // Traverse from right to left
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] >= maxFromRight) {
                result.push_back(arr[i]);
                maxFromRight = arr[i];
            }
        }

        // Reverse result since we traversed from the end
        reverse(result.begin(), result.end());
        return result;
    }
};
