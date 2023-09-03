class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;
        int freq1[26] = {0};
        int freq2[26] = {0};
        for (char c : s1)
        {
            freq1[c - 'a']++;
        }

        int i = 0, j = 0;
        while (j < s2.size())
        {
            freq2[s2[j] - 'a']++;
            if (j - i + 1 ==  s1.size())
            {
                if (check_equal(freq1, freq2)) return true;
            } 
            if (j - i + 1 < s1.size()) {
                j++;
            } else {
                freq2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }

        return false;
    }

    bool check_equal(int freq1[26], int freq2[26])
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq1[i] != freq2[i]) return false;
        }
        return true;
    }
};