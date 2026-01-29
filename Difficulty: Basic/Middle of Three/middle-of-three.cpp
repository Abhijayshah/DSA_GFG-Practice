class Solution {
  public:
    int middle(int a, int b, int c) {
        vector<int> v = {a, b, c}; // Create vector with three numbers
        sort(v.begin(), v.end()); // Sort in ascending order
        return v[1]; // Middle element is at index 1
    }
};