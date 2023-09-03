class Solution {
public:
    string longestPalindrome(string s) {
        int l = 0;
        int r = 0;

        // for each position in s, get the max palindromic substring length
        // and update the final answer
        for (int i = 0; i < s.size(); i++) {
            int palin_len1 = expand(s, i, i);
            int palin_len2 = expand(s, i, i + 1);
            int palin_max = max(palin_len1, palin_len2);
            if (palin_max > (r - l + 1)) {
                l = i - (palin_max - 1) / 2;
                r = i + (palin_max / 2);
            }
        }
        return s.substr(l, r - l + 1);
    }

    // expand left and right pointer until the substring is not palindromic 
    int expand(string s, int left, int right) {
        while (left >= 0 && right < s.size()) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
        }
        return right - left - 1;
    }
};