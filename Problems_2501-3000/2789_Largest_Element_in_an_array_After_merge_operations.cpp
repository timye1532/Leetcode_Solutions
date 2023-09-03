/* Intuition
Use a stack to solve the problem, merge the list from end to start
*/

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        stack<long> record;
        int j = nums.size() - 1;
        while (j >= 0) {
            int num = nums[j];
            if (record.empty() || record.top() < num) {
                record.push(num);
            } else {
                record.top() += num;
            }
            j--;
        }
        return record.top();
    }
};