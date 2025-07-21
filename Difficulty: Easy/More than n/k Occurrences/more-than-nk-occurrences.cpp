class Solution {
  public:
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int n = arr.size();
        
        // Count frequency of each element
        for (int num : arr) {
            freq[num]++;
        }

        int count = 0;
        // Check how many elements have frequency > n/k
        for (auto& it : freq) {
            if (it.second > n / k)
                count++;
        }

        return count;
    }
};
