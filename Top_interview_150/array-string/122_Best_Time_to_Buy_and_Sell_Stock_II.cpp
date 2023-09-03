class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            int gap = prices[i] - prices[i-1];
            res += max(gap, 0);
        }
        return res;
    }
};