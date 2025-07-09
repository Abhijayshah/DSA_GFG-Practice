class Solution {
  public:
  // Function to find the closest number to n that is divisible by m
int closestNumber(int n, int m) {
    
    int closest = 0;               // This will store the current closest number divisible by m
    int minDifference = INT_MAX;   // Initialize to a large value so that any real difference will be smaller

    // Loop through numbers in range [n - abs(m), n + abs(m)]
    // We check a small range around n to find possible divisible numbers
    for (int i = n - abs(m); i <= n + abs(m); ++i) {
        
        if (i % m == 0) {  // Check if i is divisible by m

            int difference = abs(n - i); // Find how far i is from n

            // Check if this i is closer to n than our current "closest"
            // OR if it has the same distance but larger absolute value
            if (difference < minDifference || 
               (difference == minDifference && abs(i) > abs(closest))) {
                
                closest = i;            // Update closest number
                minDifference = difference;  // Update minimum difference
            }
        }
    }

    return closest; // Return the final closest number
}
};

