#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class UnionFind {
public:
    vector<int> parent;

    UnionFind(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i; // Initialize each slot to be its own parent
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        parent[x] = y; // Union operation
    }
};

class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        
        // Create a vector of pairs (profit, deadline)
        vector<pair<int, int>> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {profit[i], deadline[i]};
        }
        
        // Sort jobs based on profit in descending order
        sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());
        
        // Initialize Union-Find structure
        UnionFind uf(n);
        
        int totalProfit = 0;
        int jobCount = 0;
        
        // Iterate through all jobs
        for (int i = 0; i < n; i++) {
            // Find the latest available slot for this job
            int availableSlot = uf.find(min(n, jobs[i].second));
            if (availableSlot > 0) { // If there is an available slot
                totalProfit += jobs[i].first; // Add profit
                jobCount++; // Increment job count
                // Union the current slot with the previous slot
                uf.unionSets(availableSlot, availableSlot - 1);
            }
        }
        
        return {jobCount, totalProfit}; // Return the result
    }
};

