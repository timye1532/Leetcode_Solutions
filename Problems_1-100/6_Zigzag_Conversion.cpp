// A   E   I  M
// B D F H J L
// C   G   k
// (ABCD), (EFGH) are groups
// each group has (numRows - 1) * 2 elements

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();

        // Dealing with special situations:
        // numRows == 1 -> original string
        if (numRows == 1 || n == 1 || numRows > n) {
            return s;
        }

        int group_len = (numRows - 1) * 2;
        string res = "";
        
        // for the first row, add the head char for each group
        for (int i = 0; i < n; i = i + group_len) {
            res += s[i];
        }
        
        // for rows between the first and last rows, add (i + j), (j + group_len - i) items if they are available
        for (int i = 1; i < (numRows - 1); i++) {
            for (int j = 0; j + i < n; j = j + group_len) {
                res += s[j + i];
                if (j + group_len - i < n) {
                    res += s[j + group_len - i];
                }
            }
        }
        
        // for the last row, add th middle char for each group
        for (int i = numRows - 1; i < n; i = i + group_len) {
            res += s[i];
        }
        
        return res;
    }
};