class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            // Move left pointer until we find 1
            while (arr[left] == 0 && left < right) left++;
            // Move right pointer until we find 0
            while (arr[right] == 1 && left < right) right--;
            
            // Swap 1 on left side with 0 on right side
            if (left < right) {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};
