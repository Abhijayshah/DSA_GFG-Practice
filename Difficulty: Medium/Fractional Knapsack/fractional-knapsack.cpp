class Solution {
  public:
  
    // Comparator to sort items based on value/weight ratio (descending)
    static bool cmp(pair<int,int> a, pair<int,int> b){
        double r1 = (double)a.first / a.second;   // value/weight of item a
        double r2 = (double)b.first / b.second;   // value/weight of item b
        return r1 > r2;   // sort in decreasing order
    }
  
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        
        int n = val.size();
        
        // Step 1: Store (value, weight) pairs
        vector<pair<int,int>> items;
        for(int i = 0; i < n; i++){
            items.push_back({val[i], wt[i]});
        }
        
        // Step 2: Sort items by value/weight ratio (descending)
        sort(items.begin(), items.end(), cmp);
        
        double totalValue = 0.0;  // final answer
        
        // Step 3: Pick items greedily
        for(int i = 0; i < n; i++){
            
            int value = items[i].first;
            int weight = items[i].second;
            
            // If we can take full item
            if(capacity >= weight){
                totalValue += value;     // add full value
                capacity -= weight;     // reduce capacity
            }
            else{
                // Take fractional part
                double fraction = (double)capacity / weight;
                totalValue += value * fraction;
                break;   // knapsack is full
            }
        }
        
        return totalValue;
    }
};