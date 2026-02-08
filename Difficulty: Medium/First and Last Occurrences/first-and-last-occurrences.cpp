class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        vector<int> result(2, -1); // Initialize result with [-1, -1]
        
        // Find first occurrence
        int s = 0, e = arr.size() - 1; // Start and end pointers
        int first = -1; // Store first occurrence index
        
        while (s <= e) { // Binary search for first occurrence
            int mid = s + (e - s) / 2; // Calculate middle index
            
            if (arr[mid] == x) { // If element found
                first = mid; // Store this index as potential first
                e = mid - 1; // Continue searching in left half for earlier occurrence
            } else if (arr[mid] < x) { // If mid value is smaller
                s = mid + 1; // Search in right half
            } else { // If mid value is larger
                e = mid - 1; // Search in left half
            }
        }
        
        result[0] = first; // Store first occurrence in result
        
        // Find last occurrence
        s = 0, e = arr.size() - 1; // Reset start and end pointers
        int last = -1; // Store last occurrence index
        
        while (s <= e) { // Binary search for last occurrence
            int mid = s + (e - s) / 2; // Calculate middle index
            
            if (arr[mid] == x) { // If element found
                last = mid; // Store this index as potential last
                s = mid + 1; // Continue searching in right half for later occurrence
            } else if (arr[mid] < x) { // If mid value is smaller
                s = mid + 1; // Search in right half
            } else { // If mid value is larger
                e = mid - 1; // Search in left half
            }
        }
        
        result[1] = last; // Store last occurrence in result
        
        return result; // Return [first, last] or [-1, -1]
    }
};