class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &it : flights)
        {
            int u = it[0];
            int v = it[1];

            int cost = it[2];
            adj[u].push_back({v, cost});
        }

        vector<int> dist(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src, 0});
        dist[src] = 0;

        int steps = 0;
        while (!q.empty() && steps <= k)
        {
            int size = q.size();

            while (size--)
            {
                int node = q.front().first;
                int dis = q.front().second;
                q.pop();

                for (auto it : adj[node])
                {
                    int adjNode = it.first;
                    int cost = it.second;

                    if (dist[adjNode] > dis + cost)
                    {
                        dist[adjNode] = dis + cost;
                        q.push({adjNode, dis + cost});
                    }
                }
            }
            steps++;
        }
        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};