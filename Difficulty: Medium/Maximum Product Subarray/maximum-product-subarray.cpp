class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        if (arr.empty()) return 0;
        
        int maxEndingHere = arr[0];
        int minEndingHere = arr[0];
        int maxSoFar = arr[0];

        for (int i = 1; i < arr.size(); ++i) {
            int curr = arr[i];
            
            // Save current maxEndingHere before updating it
            int tempMax = max({curr, maxEndingHere * curr, minEndingHere * curr});
            minEndingHere = min({curr, maxEndingHere * curr, minEndingHere * curr});
            maxEndingHere = tempMax;

            maxSoFar = max(maxSoFar, maxEndingHere);
        }

        return maxSoFar;
    }
};
