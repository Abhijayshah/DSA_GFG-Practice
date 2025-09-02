class Solution {
public:
    int binarysearch(vector<int> &arr, int k) {
        int low = 0, high = arr.size() - 1;
        int result = -1;  // stores index if found

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == k) {
                result = mid;       // possible answer
                high = mid - 1;     // move left to find smaller index
            }
            else if (arr[mid] < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return result;
    }
};
