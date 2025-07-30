class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        int n = arr.size();
        int count = 0; // total number of elements <= k

        // Step 1: Count number of elements <= k
        for (int i = 0; i < n; ++i) {
            if (arr[i] <= k) {
                ++count;
            }
        }

        // Step 2: Count number of elements > k in the first window of size `count`
        int bad = 0;
        for (int i = 0; i < count; ++i) {
            if (arr[i] > k) {
                ++bad;
            }
        }

        int minSwaps = bad;

        // Step 3: Slide the window
        for (int i = 0, j = count; j < n; ++i, ++j) {
            if (arr[i] > k) {
                --bad;
            }
            if (arr[j] > k) {
                ++bad;
            }
            minSwaps = min(minSwaps, bad);
        }

        return minSwaps;
    }
};
