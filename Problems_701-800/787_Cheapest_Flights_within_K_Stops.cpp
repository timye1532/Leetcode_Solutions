class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> mapp(n);
        for (auto f : flights)
        {
            mapp[f[0]].push_back({f[1], f[2]});
        }

        int stops = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int> price(n, INT_MAX);

        while (stops <= k && !q.empty())
        {
            int size = q.size();
            while(size--)
            {
                pair<int, int> node = q.front();
                int cur_src = node.first;
                int cur_price = node.second;
                q.pop();
                for (auto next_node : mapp[cur_src])
                {
                    int next_dst = next_node.first;
                    int next_price = next_node.second;
                    if (next_price + cur_price >= price[next_dst]) continue;
                    price[next_dst] = next_price + cur_price;
                    q.push({next_dst, price[next_dst]});
                }
            }
            stops++;
        }
        return price[dst] == INT_MAX ? -1 : price[dst];
    }
};