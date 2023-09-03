class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(nums[i]);
            res.push_back(nums[i + n]);
        }
        return res;
    }
};

// bit manipulation
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for (int i = n; i < 2 * n; i++) {
            int y_i = nums[i] << 10;
            nums[i - n] =  nums[i - n] |= y_i;
        }
        // decimal of "00000000 11111111"
        int allOnes = pow(2, 10) - 1;

        for (int i = n - 1; i >= 0; i--) {
            int x_i = nums[i] & allOnes;
            int y_i = nums[i] >> 10;
            nums[2 * i] = x_i;
            nums[2 * i + 1] = y_i;
        }
        return nums;
    }
};