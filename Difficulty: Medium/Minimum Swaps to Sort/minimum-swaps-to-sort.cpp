class Solution {
  public:
    int minSwaps(vector<int>& arr) {

        int n = arr.size();
        vector<pair<int, int>> v(n);

        // Store value with original index
        for (int i = 0; i < n; i++) {
            v[i] = {arr[i], i};
        }

        // Sort by value
        sort(v.begin(), v.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {

            // Already visited or already in correct position
            if (visited[i] || v[i].second == i)
                continue;

            int cycle_size = 0;
            int j = i;

            // Traverse the cycle
            while (!visited[j]) {
                visited[j] = true;
                j = v[j].second;
                cycle_size++;
            }

            if (cycle_size > 1)
                swaps += (cycle_size - 1);
        }

        return swaps;
    }
};
