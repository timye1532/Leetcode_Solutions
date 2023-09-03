class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusting = vector<int>(n+1);
        vector<int> trusted = vector<int>(n+1);
        for (auto p : trust)
        {
            trusting[p[0]]++;
            trusted[p[1]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (trusting[i] == 0 && trusted[i] == (n - 1)) return i;
        }
        return -1;
    }
};