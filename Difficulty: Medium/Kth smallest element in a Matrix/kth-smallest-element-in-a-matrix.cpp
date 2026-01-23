class Solution {
  public:
int kthSmallest(vector<vector<int>> &mat, int k) {
    vector<int> arr;
    for (auto &row : mat)
        for (int x : row)
            arr.push_back(x);

    sort(arr.begin(), arr.end());
    return arr[k - 1];
}

};
