class Solution {
  public:
    int search(vector<int>& arr, int x) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) {
                return i;  // return the index of first occurrence
            }
        }
        return -1;  // if element not found
    }
};
