class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // Initialize 2 pointers l, r
        int totalTime = 0;
        int n = colors.size();
        int l = 0, r = 0;
        
        while (l < n && r < n) {
            int curMax = 0;
            int curSum = 0;
            
            // restore the total removal time and the max removal time
            // for the same color group
            while (r < n && colors[l] == colors[r]) {
                curSum += neededTime[r];
                curMax = max(curMax, neededTime[r]);
                r++;
            }
            
            // remain the curMax removal time
            // add other time to total time
            totalTime += curSum - curMax;
            l = r;
        }
        return totalTime;
    }
};