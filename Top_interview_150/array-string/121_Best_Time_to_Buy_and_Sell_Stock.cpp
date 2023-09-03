class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int res = 0, temp = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            res = max(res, prices[i] - temp);
            if (prices[i] < temp) {
                temp = prices[i];
            }
        }
        return res;
    }
};
