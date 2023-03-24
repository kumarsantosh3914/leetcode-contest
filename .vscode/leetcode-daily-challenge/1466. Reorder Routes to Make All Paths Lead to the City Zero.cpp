class Solution
{
private:
    void dfs(int ind, int call, vector<vector<int>> &adjList, vector<vector<int>> &outgoing,
             vector<bool> &vis, int &ans)
    {
        vis[ind] = true;

        if (call != -1)
        {
            if (find(outgoing[ind].begin(), outgoing[ind].end(), call) == outgoing[ind].end())
                ans++;
        }
        for (auto it : adjList[ind])
        {
            if (!vis[it])
            {
                dfs(it, ind, adjList, outgoing, vis, ans);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        int ans = 0;
        vector<vector<int>> adjList(n);
        vector<vector<int>> outgoing(n);
        vector<bool> visited(n, false);
        for (auto i : connections)
        {
            adjList[i[0]].push_back(i[1]);
            adjList[i[1]].push_back(i[0]);
            outgoing[i[0]].push_back(i[1]);
        }
        dfs(0, -1, adjList, outgoing, visited, ans);
        return ans;
    }
};
