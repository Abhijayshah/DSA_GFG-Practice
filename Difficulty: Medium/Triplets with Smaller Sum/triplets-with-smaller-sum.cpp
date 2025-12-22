class Solution {
  public:
    long long countTriplets(int n, long long sum, long long arr[]) {

        sort(arr, arr + n);  // Step 1: Sort array
        long long count = 0;

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                long long currSum = arr[i] + arr[j] + arr[k];

                if (currSum < sum) {
                    // All triplets from j to k are valid
                    count += (k - j);
                    j++;
                } else {
                    k--;
                }
            }
        }

        return count;
    }
};
