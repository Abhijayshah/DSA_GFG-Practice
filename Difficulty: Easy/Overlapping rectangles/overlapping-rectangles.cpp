class Solution {
  public:
    int doOverlap(vector<int> L1, vector<int> R1, vector<int> L2, vector<int> R2) {
        // Compute normalized edges for rectangle 1
        int left1 = min(L1[0], R1[0]);
        int right1 = max(L1[0], R1[0]);
        int top1 = max(L1[1], R1[1]);
        int bottom1 = min(L1[1], R1[1]);

        // Compute normalized edges for rectangle 2
        int left2 = min(L2[0], R2[0]);
        int right2 = max(L2[0], R2[0]);
        int top2 = max(L2[1], R2[1]);
        int bottom2 = min(L2[1], R2[1]);

        // Check overlap on x-axis and y-axis
        bool overlapX = max(left1, left2) <= min(right1, right2);
        bool overlapY = max(bottom1, bottom2) <= min(top1, top2);

        return (overlapX && overlapY) ? 1 : 0;
    }
};