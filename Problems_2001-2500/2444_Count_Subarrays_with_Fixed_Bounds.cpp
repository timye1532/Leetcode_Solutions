class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int lastMin = -1, lastMax = -1;
        int leftBound = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (minK <= nums[i] && nums[i] <= maxK) {
                if (nums[i] == minK) lastMin = i;
                if (nums[i] == maxK) lastMax = i;
                int valid_subarr_cnt = max(0, min(lastMin, lastMax) - leftBound);
                res += valid_subarr_cnt;
            } else {
                lastMin = -1;
                lastMax = -1;
                leftBound = i;
            }
        }

        return res;
    }
};

/*
[(1, 3, 5), 2, 7, 5]
suppose we are now at index = 2, (1, 3, 5) is a valid fixed-bound subarrays
for currend index = 2, valid count is min(0, 2) - (-1) = 1
then we move to index = 3, "2" is also in range [minK, maxK]
for index = 3, valid count is min(0, 2) - (-1) = 1

for each index, we consider subarrays up to that index
if we meet a num that is out of range [minK, maxK], then we update lastMin and lastMax to -1
*/
