// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // Max Heap to store k smallest elements
        priority_queue<int> maxHeap;
        
        // Step 1: Insert first k elements into the heap
        for (int i = 0; i < k; i++) {
            maxHeap.push(arr[i]);
        }

        // Step 2: Check remaining elements
        for (int i = k; i < arr.size(); i++) {
            // If current element is smaller than the top of the heap
            if (arr[i] < maxHeap.top()) {
                maxHeap.pop();          // Remove the largest element
                maxHeap.push(arr[i]);   // Add the smaller element
            }
        }

        // Step 3: The top of the heap is the kth smallest element
        return maxHeap.top();
    }
};
