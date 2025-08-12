#include <vector>

class Solution {
public:
    int rowWithMax1s(std::vector<std::vector<int>> &arr) {
        int n = arr.size();
        // Check for an empty matrix
        if (n == 0) {
            return -1;
        }
        int m = arr[0].size();

        int max_row_index = -1; // Stores the index of the row with max 1s
        int col = m - 1;        // Start from the last column of the first row

        // Traverse the matrix from the top-right corner
        for (int row = 0; row < n; ++row) {
            // Move left as long as we see 1s
            while (col >= 0 && arr[row][col] == 1) {
                col--; // Move to the previous column
                max_row_index = row; // Update the candidate row
            }
        }
        
        return max_row_index;
    }
};