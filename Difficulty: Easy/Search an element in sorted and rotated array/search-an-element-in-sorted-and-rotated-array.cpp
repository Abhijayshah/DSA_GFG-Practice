int Search(vector<int> vec, int K) {
    int left = 0, right = vec.size() - 1; // Initialize two pointers at array boundaries
    
    while (left <= right) { // Binary search loop
        int mid = left + (right - left) / 2; // Calculate middle index (avoids overflow)
        
        if (vec[mid] == K) return mid; // Found the element at mid
        
        // Determine which half is sorted
        if (vec[left] <= vec[mid]) { // Left half is sorted
            if (K >= vec[left] && K < vec[mid]) { // Check if K lies in sorted left half
                right = mid - 1; // Search in left half
            } else {
                left = mid + 1; // Search in right half
            }
        } else { // Right half is sorted
            if (K > vec[mid] && K <= vec[right]) { // Check if K lies in sorted right half
                left = mid + 1; // Search in right half
            } else {
                right = mid - 1; // Search in left half
            }
        }
    }
    
    return -1; // Element not found
}