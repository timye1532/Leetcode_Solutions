class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

    int atMostK(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> freq;
        int i = 0, j = 0, diff_cnt = 0;
        while (j < nums.size()) {
            int cur = nums[j];
            if (freq[cur] == 0) diff_cnt++;
            freq[cur]++;

            while(diff_cnt > k) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) {
                    diff_cnt--;
                }
                i++;
            }
            res += (j - i + 1);
            j++;
        }
        return res;
    }
};

// # of subarrays with k distinct integers = (# of subarrays with at most k distinct integers) - 
// (# of subarrays with at most k - 1 distinct integers)

