class Solution {
  public:
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        unordered_set<int> prefixSums;
        int sum = 0;

        for (int num : arr) {
            sum += num;

            // Check if current sum is 0 or already seen
            if (sum == 0 || prefixSums.count(sum) > 0)
                return true;

            prefixSums.insert(sum);
        }

        return false;
    }
};
