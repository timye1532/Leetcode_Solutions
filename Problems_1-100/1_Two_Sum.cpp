class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> num2id;
        for (int i = 0; i < nums.size(); ++i) {
            num2id[nums[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            int to_find = target - nums[i];
            if(num2id.count(to_find) > 0 && num2id[to_find] != i) {
                return vector<int> {num2id[to_find], i};
            }
        }
        return vector<int> {0, 0};
}
};