class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        //ans store karne ke liye 
        vector<vector<int>>ans;
        // sort kar diye hai starting time se 
        sort(arr.begin(),arr.end());
        //ans me pehle wala time de diye h 
        ans.push_back(arr[0]);
        //qki 1st wala ans me pehle se h ab hm iterate uske abd se krenge
        for(int i=1;i<arr.size();i++){
            if(ans.back()[1]>=arr[i][0]){
                ans.back()[1]=max(ans.back()[1],arr[i][1]);
            }else{
                ans.push_back(arr[i]);
            }
        }
        return ans;
        
    }
};