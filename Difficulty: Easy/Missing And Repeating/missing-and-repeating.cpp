class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();
        long long S = n * (n + 1) / 2;
        long long S2 = n * (n + 1) * (2 * n + 1) / 6;
        
        long long sumArr = 0, sumSqArr = 0;
        for (long long num : arr) {
            sumArr += num;
            sumSqArr += (long long)num * num;
        }
        
        long long diff1 = sumArr - S;              // b - a
        long long diff2 = (sumSqArr - S2) / diff1; // b + a
        
        long long b = (diff1 + diff2) / 2;
        long long a = b - diff1;
        
        return {(int)b, (int)a};
    }
};
