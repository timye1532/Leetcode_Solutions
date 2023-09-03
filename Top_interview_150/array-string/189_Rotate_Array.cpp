class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        rev(nums, n - k, n - 1);
        rev(nums, 0, n - k - 1);
        rev(nums, 0, n - 1);
        return;
    }

    void rev(vector<int>& nums, int i, int j) {
        if (i >= j) return;
        while (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
        return;
    }
};