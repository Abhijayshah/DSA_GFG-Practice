#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        
        // Sort arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int platform_needed = 1; // At least one platform is needed
        int result = 1;          // To store the maximum platforms needed
        int i = 1;               // Pointer for arrival
        int j = 0;               // Pointer for departure
        
        // Traverse through all trains
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                // Train arrives before the previous departs
                platform_needed++;
                i++;
            } else {
                // A platform gets freed
                platform_needed--;
                j++;
            }
            // Update the result
            result = max(result, platform_needed);
        }
        
        return result;
    }
};
