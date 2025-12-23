class Solution {
public:
    
    // Function to count trailing zeroes in x!
    int countZeroes(int x) {
        int count = 0;
        
        // Keep dividing x by 5 to count factors of 5
        while (x > 0) {
            x = x / 5;
            count += x;
        }
        
        return count;
    }

    int findNum(int n) {
        
        int low = 0;
        int high = 5 * n;   // safe upper bound
        int ans = -1;

        // Binary search to find smallest x
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Count trailing zeroes in mid!
            if (countZeroes(mid) >= n) {
                ans = mid;        // mid is a valid answer
                high = mid - 1;   // try to find smaller x
            } else {
                low = mid + 1;    // need larger x
            }
        }

        return ans;
    }
};
