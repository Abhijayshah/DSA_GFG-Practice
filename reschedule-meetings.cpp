#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        
        // If no meetings, entire event time is free
        if (n == 0) return eventTime;
        
        // Find the maximum free time without any rescheduling
        int maxFreeTimeWithoutReschedule = calculateMaxFreeTime(eventTime, startTime, endTime);
        int maxFreeTimeWithReschedule = maxFreeTimeWithoutReschedule;
        
        // Try rescheduling each meeting
        for (int i = 0; i < n; i++) {
            int duration = endTime[i] - startTime[i];
            
            // Create a new schedule without the current meeting
            vector<int> newStart, newEnd;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    newStart.push_back(startTime[j]);
                    newEnd.push_back(endTime[j]);
                }
            }
            
            // Sort the remaining meetings
            vector<pair<int, int>> meetings;
            for (int j = 0; j < newStart.size(); j++) {
                meetings.push_back({newStart[j], newEnd[j]});
            }
            sort(meetings.begin(), meetings.end());
            
            // Try placing at the beginning
            if (duration <= eventTime) {
                vector<int> finalStart = {0};
                vector<int> finalEnd = {duration};
                for (auto& meeting : meetings) {
                    finalStart.push_back(meeting.first);
                    finalEnd.push_back(meeting.second);
                }
                int freeTime = calculateMaxFreeTime(eventTime, finalStart, finalEnd);
                maxFreeTimeWithReschedule = max(maxFreeTimeWithReschedule, freeTime);
            }
            
            // Try placing at the end
            if (duration <= eventTime) {
                vector<int> finalStart, finalEnd;
                for (auto& meeting : meetings) {
                    finalStart.push_back(meeting.first);
                    finalEnd.push_back(meeting.second);
                }
                finalStart.push_back(eventTime - duration);
                finalEnd.push_back(eventTime);
                int freeTime = calculateMaxFreeTime(eventTime, finalStart, finalEnd);
                maxFreeTimeWithReschedule = max(maxFreeTimeWithReschedule, freeTime);
            }
            
            // Try placing in the largest gap
            if (meetings.size() > 0) {
                int maxGapSize = 0;
                int bestGapStart = 0;
                
                // Gap before first meeting
                if (meetings[0].first > 0) {
                    int gapSize = meetings[0].first;
                    if (gapSize > maxGapSize && gapSize >= duration) {
                        maxGapSize = gapSize;
                        bestGapStart = 0;
                    }
                }
                
                // Gaps between meetings
                for (int j = 0; j < meetings.size() - 1; j++) {
                    int gapStart = meetings[j].second;
                    int gapEnd = meetings[j + 1].first;
                    int gapSize = gapEnd - gapStart;
                    if (gapSize > maxGapSize && gapSize >= duration) {
                        maxGapSize = gapSize;
                        bestGapStart = gapStart;
                    }
                }
                
                // Gap after last meeting
                if (meetings.back().second < eventTime) {
                    int gapSize = eventTime - meetings.back().second;
                    if (gapSize > maxGapSize && gapSize >= duration) {
                        maxGapSize = gapSize;
                        bestGapStart = meetings.back().second;
                    }
                }
                
                // If we found a suitable gap, place the meeting there
                if (maxGapSize >= duration) {
                    vector<int> finalStart, finalEnd;
                    
                    for (auto& meeting : meetings) {
                        if (meeting.first < bestGapStart) {
                            finalStart.push_back(meeting.first);
                            finalEnd.push_back(meeting.second);
                        } else {
                            // Insert our meeting before this meeting
                            finalStart.push_back(bestGapStart);
                            finalEnd.push_back(bestGapStart + duration);
                            finalStart.push_back(meeting.first);
                            finalEnd.push_back(meeting.second);
                        }
                    }
                    
                    // If no meetings were added before the gap, add our meeting first
                    if (finalStart.empty() || finalStart.back() < bestGapStart) {
                        finalStart.push_back(bestGapStart);
                        finalEnd.push_back(bestGapStart + duration);
                    }
                    
                    int freeTime = calculateMaxFreeTime(eventTime, finalStart, finalEnd);
                    maxFreeTimeWithReschedule = max(maxFreeTimeWithReschedule, freeTime);
                }
            }
        }
        
        return maxFreeTimeWithReschedule;
    }
    
private:
    int calculateMaxFreeTime(int eventTime, const vector<int>& startTime, const vector<int>& endTime) {
        int n = startTime.size();
        if (n == 0) return eventTime;
        
        int maxFree = 0;
        
        // Free time before first meeting
        maxFree = max(maxFree, startTime[0]);
        
        // Free time between meetings
        for (int i = 0; i < n - 1; i++) {
            maxFree = max(maxFree, startTime[i + 1] - endTime[i]);
        }
        
        // Free time after last meeting
        maxFree = max(maxFree, eventTime - endTime[n - 1]);
        
        return maxFree;
    }
}; 