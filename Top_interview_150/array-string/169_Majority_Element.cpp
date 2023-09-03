class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num: nums) {
            freq[num]++;
        }
        int n = nums.size();
        for (unordered_map<int, int>::iterator it=freq.begin(); it != freq.end(); it++) {
            if (it->second > n / 2) return it->first;
        }
        return 0;
    }
};