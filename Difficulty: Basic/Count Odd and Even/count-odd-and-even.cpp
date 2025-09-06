class Solution {
  public:
    /*Function to count even and odd elements in the array
     * arr : Array with its elements
     */
    pair<int, int> countOddEven(vector<int> &arr) {
        int oddCount = 0;
        int evenCount = 0;
        
        // Iterate through the array
        for (int num : arr) {
            if (num % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
        
        // Return pair with odd count first, even count second
        return make_pair(oddCount, evenCount);
    }
};