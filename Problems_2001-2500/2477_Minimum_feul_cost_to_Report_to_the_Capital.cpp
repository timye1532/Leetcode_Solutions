// dfs solution
class Solution {
private:
    long long fuel;
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        
        // build a graph to store all the connections
        vector<vector<int>> graph(n);
        for (vector<int> &e : roads) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        // use dfs to calculate the fuels
        dfs(graph, 0, -1, seats);
        return fuel;
    }

    int dfs(vector<vector<int>>& graph, int node, int prev_node, int seats) {
        int people = 1;
        // find all the neighbors connected to the current node except for parent node
        // then calculate the number of people for current node
        for (int next_node : graph[node]) {
            if (next_node == prev_node) continue;
            people += dfs(graph, next_node, node, seats);
        }

        // for n people, we could use "ceil(n / seats)" cars to carry them to the capital city
        if (node != 0) {
            fuel += (people + seats - 1) / seats;
        }
        return people;
    }
};