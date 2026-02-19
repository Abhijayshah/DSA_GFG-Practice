class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        
        int xorAll = 0; // Will store XOR of all elements
        
        // Step 1: XOR all elements
        for (int num : arr) {
            xorAll ^= num; // Pairs cancel out, result = x ^ y
        }
        
        // Step 2: Find rightmost set bit (differentiating bit)
        int rightmostSetBit = xorAll & (-xorAll);
        
        int num1 = 0, num2 = 0; // Store the two unique numbers
        
        // Step 3: Divide elements into two groups
        for (int num : arr) {
            
            // If the bit is set, XOR in first group
            if (num & rightmostSetBit)
                num1 ^= num;
            else
                num2 ^= num;
        }
        
        // Step 4: Return result in increasing order
        if (num1 < num2)
            return {num1, num2};
        else
            return {num2, num1};
    }
};
