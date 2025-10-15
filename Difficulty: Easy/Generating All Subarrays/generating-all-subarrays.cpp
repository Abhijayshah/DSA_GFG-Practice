class Solution {
public:
    vector<vector<int>> ans;
    
    void generate(vector<int>& arr, int start, int end) {
        int n = arr.size();
        // base case: when start crosses end of array
        if (start == n) return;
        
        // if end is within range, take subarray and move end forward
        if (end < n) {
            vector<int> sub(arr.begin() + start, arr.begin() + end + 1);
            ans.push_back(sub);
            generate(arr, start, end + 1);
        } 
        else {
            // move start forward and reset end = start
            generate(arr, start + 1, start + 1);
        }
    }

    vector<vector<int>> getSubArrays(vector<int>& arr) {
        ans.clear();
        generate(arr, 0, 0);
        return ans;
    }
};
