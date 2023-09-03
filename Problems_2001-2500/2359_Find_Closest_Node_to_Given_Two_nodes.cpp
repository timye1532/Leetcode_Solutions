class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1 = vector<int>(n, 0);
        vector<int> dist2 = vector<int>(n, 0);
        vector<bool> visit1 = vector<bool>(n, false);
        vector<bool> visit2 = vector<bool>(n, false);

        dfs(dist1, visit1, edges, node1);
        dfs(dist2, visit2, edges, node2);
        int res = -1;
        int minDist = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (visit1[i] == true && visit2[i] == true && max(dist1[i], dist2[i]) < minDist)
            {
                minDist = max(dist1[i], dist2[i]);
                res = i;
            }
        }

        return res;
    }

    void dfs(vector<int>& dist, vector<bool>& visited, vector<int>& edges, int node)
    {   
        visited[node] = true;
        int next_node = edges[node];
        if (next_node != -1 && visited[next_node] == false)
        {
            dist[next_node] = dist[node] + 1;
            dfs(dist, visited, edges, next_node);
        }
        return;
    }

};