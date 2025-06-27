// User function template for C++

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int maxSum = INT_MIN; // to store the maximum sum
        int currentSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            currentSum += arr[i];         // add current element
            maxSum = max(maxSum, currentSum); // update max sum if needed

            if (currentSum < 0) {
                currentSum = 0; // reset if current sum becomes negative
            }
        }

        return maxSum;
    }
};
