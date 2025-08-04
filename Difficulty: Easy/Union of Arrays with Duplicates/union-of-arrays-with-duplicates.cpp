class Solution {
public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        set<int> unionSet;
        
        // Insert all elements from both arrays
        for(int x : a) {
            unionSet.insert(x);
        }
        for(int x : b) {
            unionSet.insert(x);
        }
        
        // Convert set to vector and return
        vector<int> result(unionSet.begin(), unionSet.end());
        return result;
    }
};