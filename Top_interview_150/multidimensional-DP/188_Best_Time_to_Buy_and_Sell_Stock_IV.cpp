class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp((k+1), vector<int>(n, 0));

        for (int t = 1; t <= k; t++) {
            int flag = prices[0];
            for (int i = 1; i < n; i++) {
                flag = min(flag, prices[i] - dp[t-1][i-1]);
                dp[t][i] = max(dp[t][i-1], prices[i] - flag);
            }
        }
        return dp[k][n-1];
    }
};