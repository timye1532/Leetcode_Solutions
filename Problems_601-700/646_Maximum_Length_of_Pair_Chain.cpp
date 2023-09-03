// check problem 300, same idea, dynamic programming
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int res = 0;
        int n = pairs.size();
        int dp[n];

        sort(pairs.begin(), pairs.end());
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};