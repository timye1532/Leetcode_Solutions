class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // initialize l, r pointer, num_dict map
        int l = 0, r = 0;
        int res = 0;
        unordered_map<char, int> num_dict;

        while (r < s.length()){
            char cur_char = s[r];

            // update the frequency for current char
            if (num_dict.count(cur_char) == 0){
                num_dict[cur_char] = 1;
            } else {
                num_dict[cur_char] += 1;
            }

            // move left pointer until the frequency of 
            // current char become 1
            while (l < r && (num_dict[cur_char] >= 2)){
                char left_char = s[l];
                num_dict[left_char] -= 1;
                l++;
            }

            // update the answer
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};