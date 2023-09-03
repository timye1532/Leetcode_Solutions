/* Intuition
use DFS, like n = 24
start with [2, 12], add this to result
then keep [2, ], factorize 12 to continue, record the path
*/
class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> path;
        backtrace(n, 2, path);
        return res;
    }

    void backtrace(int n, int start_factor, vector<int>& path) {
        for (int i = start_factor; i < int(sqrt(n)) + 1; i++) {
            if (n % i == 0) {
                int rest = n / i;
                path.push_back(i);
                path.push_back(rest);
                res.push_back(path);
                path.pop_back();
                backtrace(rest, i, path);
                path.pop_back();
            }
        }
        return;
    }
};