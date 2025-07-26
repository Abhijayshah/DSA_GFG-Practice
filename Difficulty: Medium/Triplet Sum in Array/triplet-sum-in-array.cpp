class Solution {
public:
    bool hasTripletSum(vector<int> &arr, int target) {
        int n = arr.size();
        sort(arr.begin(), arr.end()); // Step 1: Sort the array
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = arr[i] + arr[left] + arr[right];
                
                if (currentSum == target) {
                    return true; // Triplet found
                } else if (currentSum < target) {
                    left++; // Move to a bigger sum
                } else {
                    right--; // Move to a smaller sum
                }
            }
        }
        return false; // No triplet found
    }
};









