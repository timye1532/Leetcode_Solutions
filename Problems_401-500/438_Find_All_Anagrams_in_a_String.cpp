class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return vector<int>{};
        vector<int> res;
        int freq1[26] = {0};
        int freq2[26] = {0};

        int l = 0, r = p.size() - 1;
        for (int i = l; i <= r; i++) {
            freq1[s[i] - 'a']++;
            freq2[p[i] - 'a']++;
        }

        while (r < s.size()) {
            if (check_equal(freq1, freq2)) res.push_back(l);
            freq1[s[l] - 'a']--;
            l++;
            if (r + 1 < s.size()) {
                freq1[s[r + 1] - 'a']++;
            }
            r++;
        }

        return res;
    }

    bool check_equal(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) return false;
        }
        return true;
    }
};