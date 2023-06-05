class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adjList[])
    {
        vis[node] = 1;
        for (auto it : adjList[node])
        {
            if (vis[it] == 0)
            {
                dfs(it, vis, adjList);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // make adjList
        int n = isConnected.size();
        vector<int> adjList[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        // visited array
        vector<int> visited(n, 0);
        // find provinces
        int countProvinces = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                countProvinces++;
                dfs(i, visited, adjList);
            }
        }
        return countProvinces;
    }
};