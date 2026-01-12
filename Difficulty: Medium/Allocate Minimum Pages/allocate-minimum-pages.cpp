class Solution {
  public:

    // Helper function to check feasibility
    bool isPossible(vector<int> &arr, int k, int maxPages) {
        int students = 1;
        int pages = 0;

        for (int i = 0; i < arr.size(); i++) {

            // If adding this book exceeds limit
            if (pages + arr[i] > maxPages) {
                students++;
                pages = arr[i];

                if (students > k)
                    return false;
            }
            else {
                pages += arr[i];
            }
        }

        return true;
    }

    int findPages(vector<int> &arr, int k) {

        int n = arr.size();

        // Edge case
        if (k > n) return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = 0;

        for (int pages : arr)
            high += pages;

        int answer = -1;

        // Binary Search on Answer
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, k, mid)) {
                answer = mid;      // possible answer
                high = mid - 1;    // try smaller maximum
            }
            else {
                low = mid + 1;     // increase limit
            }
        }

        return answer;
    }
};
