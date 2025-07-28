class Solution {
  public:
    double findMedian(vector<int> &arr) {
        sort(arr.begin(), arr.end());  // Step 1: Sort the array
        
        int n = arr.size();
        
        // Step 2: Check if size is odd or even
        if (n % 2 == 1) {
            return arr[n / 2]; // Odd size: middle element
        } else {
            // Even size: average of two middle elements
            return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        }
    }
};
