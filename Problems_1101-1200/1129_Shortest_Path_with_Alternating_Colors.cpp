class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n, -1);
        vector<bool> visit1(n, false), visit2(n, false);
        vector<vector<pair<int, int>>> mapp(n);

        // store all the connections in mapp, 1 for red, 2 for blue
        for (auto &e : redEdges) {
            mapp[e[0]].push_back({e[1], 1});
        }
        for (auto &e : blueEdges) {
            mapp[e[0]].push_back({e[1], 2});
        }

        // special for "0"
        res[0] = 0;
        visit1[0] = true;
        visit2[0] = true;
        int step = 1;

        // construct a queue, and start the BFS
        queue<pair<int, int>> q;
        for (auto &node : mapp[0]) {
            q.push(node);
            if (res[node.first] == -1) res[node.first] = step;
        }

        while (!q.empty()) {
            int l = q.size();
            step++;
            for (int i = 0; i < l; i++) {
                auto node = q.front();
                q.pop();

                // change the visit1/visit2 status
                if (node.second == 1) {
                    visit1[node.first] = true;
                } else {
                    visit2[node.first] = true;
                }
                
                // for next node
                // if it's color is same with current node, we cannot continue
                // or the next node is already visited
                for (auto &next_node : mapp[node.first]) {
                    if (node.second == 1 && (visit2[next_node.first] || next_node.second == 1)) continue;
                    if (node.second == 2 && (visit1[next_node.first] || next_node.second == 2)) continue;
                    q.push(next_node);
                    if (res[next_node.first] == -1) res[next_node.first] = step;
                }
            }
        }


        return res;
    }
};