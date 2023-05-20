class Solution
{
private:
    // bool bipartiteDfs(int node, vector<vector<int>>& graph, vector<int> &color) {
    //     if(color[node] == -1) color[node] = 1;
    //     for(auto it:graph[node]) {
    //         if(color[it] == -1) {
    //             color[it] = 1 - color[node];
    //             if(!bipartiteDfs(it, graph, color)) {
    //                 return false;
    //             }
    //         }
    //         else if(color[it] == color[node]) return false;
    //     }
    //     return true;
    // }
    bool bipartiteBfs(int start, vector<vector<int>> &graph, vector<int> &color)
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto it : graph[node])
            {
                // if the adjacent node is not yet colored
                // you will give the opposite color of the node
                if (color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                // if the adjacent guy having the same color
                // someone did color it on the some other path
                else if (color[it] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!bipartiteBfs(i, graph, color))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
