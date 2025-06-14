// User function Template for C++
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        // code here
        int n = arr.size();
        sort(arr.begin() , arr.end());
        pair<int,int> p = make_pair(arr[0] , arr[n-1]);
        return p;
        
    }
};
