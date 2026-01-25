class Solution {
  public:
    bool canPaint(vector<int>& arr, int k, long long maxTime) {
        long long currSum = 0;
        int painters = 1;

        for (int len : arr) {
            if (currSum + len <= maxTime) {
                currSum += len;
            } else {
                painters++;
                currSum = len;
                if (painters > k)
                    return false;
            }
        }
        return true;
    }

    int minTime(vector<int>& arr, int k) {

        int n = arr.size();

        long long low = 0, high = 0;
        for (int x : arr) {
            low = max(low, (long long)x);
            high += x;
        }

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (canPaint(arr, k, mid)) {
                ans = mid;          // possible answer
                high = mid - 1;     // try smaller
            } else {
                low = mid + 1;      // need more time
            }
        }

        return ans;
    }
};
