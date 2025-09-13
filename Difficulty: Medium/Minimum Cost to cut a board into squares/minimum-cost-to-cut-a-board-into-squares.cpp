class Solution {
public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        // Sort both arrays in descending order (highest cost first)
        sort(x.begin(), x.end(), greater<int>());
        sort(y.begin(), y.end(), greater<int>());
        
        int totalCost = 0;
        int horizontalSegments = 1;  // Initially 1 horizontal segment
        int verticalSegments = 1;    // Initially 1 vertical segment
        
        int i = 0, j = 0;  // Pointers for x and y arrays
        
        // Process all cuts using greedy approach
        while (i < x.size() && j < y.size()) {
            // Choose the cut with higher cost
            if (x[i] >= y[j]) {
                // Make vertical cut
                totalCost += x[i] * horizontalSegments;
                verticalSegments++;
                i++;
            } else {
                // Make horizontal cut
                totalCost += y[j] * verticalSegments;
                horizontalSegments++;
                j++;
            }
        }
        
        // Process remaining vertical cuts
        while (i < x.size()) {
            totalCost += x[i] * horizontalSegments;
            verticalSegments++;
            i++;
        }
        
        // Process remaining horizontal cuts
        while (j < y.size()) {
            totalCost += y[j] * verticalSegments;
            horizontalSegments++;
            j++;
        }
        
        return totalCost;
    }
};