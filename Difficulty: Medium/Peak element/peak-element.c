// Function to find the peak element
int peakElement(int *arr, int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // If mid element is smaller than next, peak is on right side
        if (arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        } else {
            // Else peak lies on left side including mid
            high = mid;
        }
    }

    return low; // low (or high) will be at a peak element
}

