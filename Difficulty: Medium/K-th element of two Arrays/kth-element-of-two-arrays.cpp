class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        
        int n = a.size(); // Size of first array
        int m = b.size(); // Size of second array
        
        // Always perform binary search on smaller array
        if (n > m)
            return kthElement(b, a, k);
        
        // Define search space for elements taken from array 'a'
        int low = max(0, k - m);   // Minimum elements from 'a'
        int high = min(k, n);      // Maximum elements from 'a'
        
        while (low <= high) {
            
            int cutA = low + (high - low) / 2; // Elements taken from 'a'
            int cutB = k - cutA;               // Elements taken from 'b'
            
            // Handle boundaries carefully
            int leftA  = (cutA == 0) ? INT_MIN : a[cutA - 1];
            int leftB  = (cutB == 0) ? INT_MIN : b[cutB - 1];
            int rightA = (cutA == n) ? INT_MAX : a[cutA];
            int rightB = (cutB == m) ? INT_MAX : b[cutB];
            
            // Check if correct partition is found
            if (leftA <= rightB && leftB <= rightA) {
                return max(leftA, leftB); // kth element found
            }
            else if (leftA > rightB) {
                high = cutA - 1; // Move search space left
            }
            else {
                low = cutA + 1;  // Move search space right
            }
        }
        
        return -1; // This line should not be reached if input is valid
    }
};
