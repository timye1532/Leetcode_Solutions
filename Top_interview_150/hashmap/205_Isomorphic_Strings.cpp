/* Intuition
Use two hash maps
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> st;
        unordered_map<char, char> ts;
        
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            char chr_s = s[i];
            char chr_t = t[i];
            if (st.count(chr_s) == 0 && ts.count(chr_t) == 0) {
                st[chr_s] = chr_t;
                ts[chr_t] = chr_s;
            } else if (st.count(chr_s) == 0 || ts.count(chr_t) == 0) {
                return false;
            } else if (st[chr_s] != chr_t || ts[chr_t] != chr_s) {
                return false;
            }
        }
        return true;
    }
};