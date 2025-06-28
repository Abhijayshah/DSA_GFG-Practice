// User function template for C++

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        // If array size is 1 or already at the end, no jump needed
        if (n <= 1) return 0;

        // If first element is 0, can't move anywhere
        if (arr[0] == 0) return -1;

        // maxReach = farthest index we can reach so far
        int maxReach = arr[0];
        // steps = steps we can still take in the current jump
        int steps = arr[0];
        // jumps = number of jumps we have taken
        int jumps = 1;

        // Start from the second element (index 1)
        for (int i = 1; i < n; i++) {
            // If we reach the last element
            if (i == n - 1) {
                return jumps;
            }

            // Update maxReach
            maxReach = max(maxReach, i + arr[i]);

            // Use a step to move forward
            steps--;

            // If no more steps left
            if (steps == 0) {
                // We need to take another jump
                jumps++;

                // If current position is beyond or at maxReach, can't move forward
                if (i >= maxReach) {
                    return -1;
                }

                // Re-initialize the steps for new jump
                steps = maxReach - i;
            }
        }

        // If we finish loop without reaching end
        return -1;
    }
};
