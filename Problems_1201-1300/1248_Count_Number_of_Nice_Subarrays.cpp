class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        vector<int> odd_idx;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 1) odd_idx.push_back(i);
        }

        if (odd_idx.size() < k) return 0;
        odd_idx.push_back(n);
        
        int l = 0, r = l + k - 1;
        int leftBound = -1;

        while (r < odd_idx.size() - 1) {
            int rightBound = odd_idx[r + 1];
            int left_comb = odd_idx[l] - leftBound;
            int right_comb = rightBound - odd_idx[r];
            res += left_comb * right_comb;
            leftBound = odd_idx[l];
            l++;
            r++;
        }

        return res;
    }
};