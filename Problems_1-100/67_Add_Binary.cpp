class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        int pa = a.size() - 1, pb = b.size() - 1;

        while (pa >= 0 && pb >= 0) {
            int cur = a[pa] - '0' + b[pb] - '0' + carry;
            if (cur == 0 || cur == 2) {
                res = '0' + res;
            } else if (cur == 1 || cur == 3) {
                res = '1' + res;
            }
            if (cur >= 2) 
                carry = 1;
            else
                carry = 0;
            pa--;
            pb--;
        }

        while (pa >= 0) {
            int cur = a[pa] - '0' + carry;
            if (cur == 0 || cur == 2) {
                res = '0' + res;
            } else if (cur == 1) {
                res = '1' + res;
            }
            if (cur == 2)
                carry = 1;
            else
                carry = 0;
            pa--;
        }

        while (pb >= 0) {
            int cur = b[pb] - '0' + carry;
            if (cur == 0 || cur == 2) {
                res = '0' + res;
            } else if (cur == 1) {
                res = '1' + res;
            }
            if (cur == 2)
                carry = 1;
            else
                carry = 0;
            pb--;
        }
        if (carry == 1) res = '1' + res;
        return res;
    }
};