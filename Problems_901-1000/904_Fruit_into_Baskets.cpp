class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0, l = 0, r = 0;
        int num_typs = 0;
        unordered_map<int, int> freq;

        while (r < fruits.size()) {
            int cur_type = fruits[r];
            if (freq.find(cur_type) == freq.end() || freq[cur_type] == 0) {
                num_typs++;
                freq[cur_type] = 1;
            } else {
                freq[cur_type]++;
            }
            while (l < r && num_typs > 2) {
                int last_type = fruits[l];
                freq[last_type]--;
                if (freq[last_type] == 0) num_typs--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};