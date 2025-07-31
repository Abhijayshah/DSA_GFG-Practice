class Solution {
public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int n = arr.size();
        int min_len = n + 1;
        int sum = 0, start = 0, end = 0;

        while (end < n) {
            // Add elements until sum becomes greater than x
            while (sum <= x && end < n)
                sum += arr[end++];

            // Try to minimize the window size
            while (sum > x && start < n) {
                min_len = min(min_len, end - start);
                sum -= arr[start++];
            }
        }

        // If no valid subarray found
        return (min_len == n + 1) ? 0 : min_len;
    }
};
