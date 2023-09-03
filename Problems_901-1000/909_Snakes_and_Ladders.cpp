class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int res = bfs(board, 1, n);
        return res;
    }

    int bfs(vector<vector<int>>& board, int start, int n)
    {
        queue<int> q;
        q.push(start);
        set<int> visited;
        visited.insert(start);
        int step = 0;

        while (!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int pos = q.front();
                q.pop();
                if (pos == n * n) return step;

                for (int i = 1; i <= 6; i++)
                {
                    int next_pos = min(pos + i, n * n);
                    vector<int> idx = get_idx_from_pos(next_pos, n);
                    int next_x = idx[0];
                    int next_y = idx[1];
                    if (board[next_x][next_y] != -1)
                    {
                        next_pos = board[next_x][next_y];
                    }
                    if (visited.find(next_pos) != visited.end()) continue;
                    q.push(next_pos);
                    visited.insert(next_pos);
                }
            }
            step++;
        }
        return -1;
    }

    vector<int> get_idx_from_pos(int pos, int n)
    {
        pos--;
        int r = pos / n;
        int c = pos % n;
        if (r % 2 == 1) c = (n - 1) - c;
        r = (n - 1) - r;
        return vector<int>{r, c};
    }
};