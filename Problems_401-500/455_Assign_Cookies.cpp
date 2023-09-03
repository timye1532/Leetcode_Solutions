/* Intuition
To maximize the number of children who can be content with the cookies they recieve.
We first sort the two arrays, and start with the smallest greed factors to see if we could satisfy the current children. If true, we move to next child, if not we add the index of cookie array to check this condition again

*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0, i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) {
                res++;
                i++;
            }
            j++;
        }
        return res;
    }
};