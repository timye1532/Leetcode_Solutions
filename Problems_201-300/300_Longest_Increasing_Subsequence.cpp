class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int dp[n];

        // dp[i] means the longest length we can get at position i
        for (int i = 0; i < n; i++)
        {
            // at first, we get position i itself, so length=1
            // then we check all the positions before position i
            // if nums[j] < nums[i], we update current dp[i]
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};