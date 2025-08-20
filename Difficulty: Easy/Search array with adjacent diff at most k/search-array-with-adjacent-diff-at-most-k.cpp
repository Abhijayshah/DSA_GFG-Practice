class Solution {
  public:
    int findStepKeyIndex(vector<int>& arr, int k, int x) {
        int i = 0;
        int n = arr.size();
        
        while (i < n) {
            if (arr[i] == x) {
                return i;
            }
            
            // Calculate minimum steps needed to reach x from current position
            // Since adjacent elements can differ by at most k,
            // we need at least |arr[i] - x| / k steps to reach x
            int diff = abs(arr[i] - x);
            int steps = max(1, diff / k);
            
            i += steps;
        }
        
        return -1;
    }
};