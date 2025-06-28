// User function template for C++

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if (n <= 1) return 0;              // If already at or beyond last index, no jumps needed
        if (arr[0] == 0) return -1;        // If first element is 0, can't move anywhere

        int maxReach = arr[0];             // Max index we can reach initially
        int steps = arr[0];                // Steps we can still take in current jump
        int jumps = 1;                     // We have taken at least one jump to start

        for (int i = 1; i < n; i++) {     // Start loop from index 1
            if (i == n - 1)               // If we reach the last index
                return jumps;             // Return number of jumps

            maxReach = max(maxReach, i + arr[i]); // Update the farthest we can reach

            steps--;                       // Use a step to move to next index

            if (steps == 0) {             // If no more steps left
                jumps++;                  // We need to jump

                if (i >= maxReach)       // If current index is beyond maxReach, can't move forward
                    return -1;           // Return -1 as we are stuck

                steps = maxReach - i;    // Reset steps for new jump window
            }
        }

        return -1;                        // If end is not reachable after loop
    }
};
