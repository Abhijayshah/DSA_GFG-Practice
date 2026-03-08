class Solution {
public:
    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d) {
        
        vector<int> out(n+1, 0);
        vector<int> in(n+1, 0);
        vector<int> dia(n+1, 0);

        // store pipe information
        for(int i=0;i<p;i++){
            out[a[i]] = b[i];
            dia[a[i]] = d[i];
            in[b[i]] = 1;
        }

        vector<vector<int>> ans;

        for(int i=1;i<=n;i++){
            
            // tank condition
            if(in[i]==0 && out[i]!=0){
                
                int start = i;
                int minDia = INT_MAX;
                int j = i;

                while(out[j] != 0){
                    minDia = min(minDia, dia[j]);
                    j = out[j];
                }

                int end = j;
                ans.push_back({start, end, minDia});
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};