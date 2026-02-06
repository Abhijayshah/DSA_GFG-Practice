class Solution {
  public:
int findMin(vector<int>& arr) {
    int mn = arr[0];
    for (int x : arr) {
        mn = min(mn, x);
    }
    return mn;
}

};