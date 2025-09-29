class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        if (arr.empty()) return 0;

        sort(arr.begin(), arr.end());
        int count = 1; // At least one subset exists

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != arr[i - 1] + 1) {
                count++; // start new subset
            }
        }
        return count;
    }
};






