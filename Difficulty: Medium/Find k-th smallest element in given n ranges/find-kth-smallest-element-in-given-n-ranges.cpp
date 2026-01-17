class Solution {
  public:
    vector<int> kthSmallestNum(int n, vector<vector<int>>& range, int q,
                               vector<int> queries) {

        // Step 1: Sort ranges by starting value
        sort(range.begin(), range.end());

        // Step 2: Merge overlapping ranges
        vector<pair<long long, long long>> merged;

        for (auto &r : range) {
            long long start = r[0];
            long long end = r[1];

            if (merged.empty() || merged.back().second < start - 1) {
                merged.push_back({start, end});
            } else {
                merged.back().second = max(merged.back().second, end);
            }
        }

        // Step 3: Answer queries
        vector<int> ans;

        for (int k : queries) {
            long long temp = k;
            bool found = false;

            for (auto &r : merged) {
                long long count = r.second - r.first + 1;

                if (temp <= count) {
                    ans.push_back(r.first + temp - 1);
                    found = true;
                    break;
                } else {
                    temp -= count;
                }
            }

            if (!found)
                ans.push_back(-1);
        }

        return ans;
    }
};
