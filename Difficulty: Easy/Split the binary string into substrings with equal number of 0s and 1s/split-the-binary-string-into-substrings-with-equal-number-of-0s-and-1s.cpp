class Solution {
public:
    int maxSubStr(string str) {
        int count0 = 0, count1 = 0;
        int result = 0;

        for (char c : str) {
            if (c == '0') count0++;
            else count1++;

            if (count0 == count1) {
                result++;
            }
        }

        // If total 0s != total 1s, split is not possible
        if (count0 != count1) return -1;
        
        return result;
    }
};
