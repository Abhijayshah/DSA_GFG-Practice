#include <unordered_map>
using namespace std;

class Solution {
  public:
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_map<int, int> lastIndex;  // element -> last index

        for (int i = 0; i < arr.size(); i++) {
            if (lastIndex.find(arr[i]) != lastIndex.end()) {
                if (i - lastIndex[arr[i]] <= k) {
                    return true;
                }
            }
            lastIndex[arr[i]] = i;  // update last seen index
        }
        return false;
    }
};
