class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int k = 1, cnt = 1;
        int temp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == temp) {
                cnt++;
                if (cnt <= 2) nums[k++] = nums[i];
            } else {
                temp = nums[i];
                cnt = 1;
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};