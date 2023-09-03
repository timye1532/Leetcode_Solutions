class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int k = 1, i = 1;
        while (i < nums.size()) {
            if (nums[i] == nums[i - 1]) {
                i++;
            } else {
                nums[k++] = nums[i++];
            }
        }
        return k;
    }
};