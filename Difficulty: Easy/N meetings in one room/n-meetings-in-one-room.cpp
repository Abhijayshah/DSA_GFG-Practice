class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        
        int n = start.size(); // Total number of meetings
        
        // Store meetings as {end, start}
        vector<pair<int,int>> meetings;
        
        for(int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]}); // Store end time first
        }
        
        // Sort meetings based on earliest end time
        sort(meetings.begin(), meetings.end());
        
        int count = 1; // First meeting always selected
        int lastEnd = meetings[0].first; // End time of last selected meeting
        
        // Traverse remaining meetings
        for(int i = 1; i < n; i++) {
            
            // If meeting starts after last meeting ends
            if(meetings[i].second > lastEnd) {
                
                count++; // Select this meeting
                lastEnd = meetings[i].first; // Update last end time
            }
        }
        
        return count; // Return maximum meetings
    }
};