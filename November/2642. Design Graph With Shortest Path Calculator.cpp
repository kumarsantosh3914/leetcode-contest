class Graph
{
private:
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int n, vector<vector<int>> &edges)
    {
        adjList.resize(n);
        for (auto it : edges)
        {
            adjList[it[0]].push_back({it[1], it[2]});
        }
    }

    void addEdge(vector<int> edge)
    {
        adjList[edge[0]].push_back({edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2)
    {
        int n = adjList.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[node1] = 0;
        pq.push(make_pair(0, node1));

        while (!pq.empty())
        {
            int d = pq.top().first, node = pq.top().second;
            pq.pop();
            if (node == node2)
                return d;
            if (d > dist[node])
                continue;
            for (auto &neighbor : adjList[node])
            {
                int new_dist = d + neighbor.second;
                if (new_dist < dist[neighbor.first])
                {
                    dist[neighbor.first] = new_dist;
                    pq.push(make_pair(new_dist, neighbor.first));
                }
            }
        }
        return -1;
    }
};
/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */