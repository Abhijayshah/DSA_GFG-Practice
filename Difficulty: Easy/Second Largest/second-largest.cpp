class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int largest = -1;
        int secondLargest = -1;
        
        // Find the largest element
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > largest) {
                largest = arr[i];
            }
        }
        
        // Find the second largest element (strictly smaller than largest)
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != largest && arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }
        
        return (secondLargest == -1) ? -1 : secondLargest;
    }
};
