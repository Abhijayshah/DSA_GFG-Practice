// User function template for C++

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int gap = (n + m + 1) / 2;         // Initial gap (ceil)

        while (gap > 0) {
            int i = 0;
            int j = gap;

            while (j < n + m) {           // Loop till end of combined virtual array
                int val1, val2;

                // Get first value (from a or b)
                if (i < n) val1 = a[i];
                else val1 = b[i - n];

                // Get second value (from a or b)
                if (j < n) val2 = a[j];
                else val2 = b[j - n];

                if (val1 > val2) {
                    // Swap in a
                    if (i < n && j < n) swap(a[i], a[j]);
                    // Swap between a and b
                    else if (i < n && j >= n) swap(a[i], b[j - n]);
                    // Swap in b
                    else if (i >= n && j >= n) swap(b[i - n], b[j - n]);
                }

                i++;
                j++;
            }

            if (gap == 1) gap = 0;         // Last iteration
            else gap = (gap + 1) / 2;      // Next reduced gap (ceil)
        }
    }
};
