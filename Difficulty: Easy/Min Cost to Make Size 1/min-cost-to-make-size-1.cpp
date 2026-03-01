class Solution {
  public:

    int cost(vector<int>& arr) {
        
        int n = arr.size(); // Size of array
        
        // If only one element, no cost needed
        if (n == 1)
            return 0;
        
        // Find minimum element in array
        int minElement = *min_element(arr.begin(), arr.end());
        
        long long totalCost = 0; // Store total cost
        
        // Each of the other (n-1) elements must be removed
        // Best strategy: always pair them with smallest element
        totalCost = 1LL * minElement * (n - 1);
        
        return totalCost; // Return minimum cost
    }
};