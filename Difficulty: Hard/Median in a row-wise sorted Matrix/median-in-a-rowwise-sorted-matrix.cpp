class Solution {
  public:
    int countSmallerThanEqual(vector<int>& row, int target) {
        // Using upper_bound to find the count of elements <= target
        return upper_bound(row.begin(), row.end(), target) - row.begin();
    }

    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        int low = 1, high = 2000; // Given constraint
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int count = 0;
            
            for (int i = 0; i < n; i++) {
                count += countSmallerThanEqual(mat[i], mid);
            }
            
            if (count < (n * m + 1) / 2)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return low;
    }
};
