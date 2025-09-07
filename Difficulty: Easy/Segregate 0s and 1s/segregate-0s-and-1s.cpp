class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;
        
        while (left < right) {
            // move left forward if it's already 0
            while (left < right && arr[left] == 0) {
                left++;
            }
            
            // move right backward if it's already 1
            while (left < right && arr[right] == 1) {
                right--;
            }
            
            // if left is 1 and right is 0 -> swap
            if (left < right) {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};
