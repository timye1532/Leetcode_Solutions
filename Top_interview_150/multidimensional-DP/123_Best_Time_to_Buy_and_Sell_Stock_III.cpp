/* Intuition
dp[k][i] = max(dp[k][i-1], prices[i] - prices[j] + dp[k-1][j-1]) for j in range(0, i)
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       if (n == 0) return 0;

       int dp[3][n];
       for (int i = 0; i < n; i++) {
           dp[0][i] = 0;
       }
       for (int i = 1; i < 3; i++) {
           dp[i][0] = 0;
       }

       for (int k = 1; k <= 2; k++) {
           int flag = prices[0];
           for (int i = 1; i < n; i++) {
               flag = min(flag, prices[i] - dp[k-1][i-1]);
               dp[k][i] = max(dp[k][i-1], prices[i] - flag);
           }
       }
       return dp[2][n-1];
    }
};
