class Solution {
  public:
    int transform(string A, string B) {
        
        // If lengths are different, transformation is impossible
        if (A.length() != B.length())
            return -1;
        
        int n = A.length(); // Store length
        
        // Step 1: Check if both strings have same character frequency
        int count[256] = {0}; // Frequency array for ASCII characters
        
        for (int i = 0; i < n; i++) {
            count[A[i]]++; // Increment count for A
            count[B[i]]--; // Decrement count for B
        }
        
        // If any frequency is not zero, strings are not anagrams
        for (int i = 0; i < 256; i++) {
            if (count[i] != 0)
                return -1; // Not possible to transform
        }
        
        // Step 2: Count minimum operations
        int i = n - 1; // Pointer for A
        int j = n - 1; // Pointer for B
        int operations = 0; // Count operations
        
        while (i >= 0) {
            
            // If characters match, move both pointers
            if (A[i] == B[j]) {
                i--;
                j--;
            }
            else {
                // If not matching, this character needs to be moved
                operations++;
                i--; // Move pointer of A only
            }
        }
        
        return operations; // Return minimum steps
    }
};
