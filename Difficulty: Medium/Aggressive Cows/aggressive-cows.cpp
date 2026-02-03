class Solution {
  public:
    bool good(vector<int>&stalls,int k,int dis){
        int first=stalls[0];
        int count=1;
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-first>=dis){
                count++;
                first=stalls[i];
            }
        }
        if(count>=k)return true;
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n=stalls.size();
        int low=1, high=stalls[n-1]-stalls[0];
        int ans=0;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(good(stalls,k,mid)){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
        
    }
};

