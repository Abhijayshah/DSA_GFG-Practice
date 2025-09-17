class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int j = 0; // index of next non-zero position
        
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                if (i != j) {
                    swap(arr[i], arr[j]);
                }
                j++;
            }
        }
    }
};
