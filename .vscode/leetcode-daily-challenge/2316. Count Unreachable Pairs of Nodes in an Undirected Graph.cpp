class Solution
{
private:
    long long dfs(vector<vector<int>> &mp, int node, vector<bool> &vis)
    {
        if (vis[node])
            return 0;
        vis[node] = true;
        long long cnt = 1;
        for (int i = 0; i < mp[node].size(); i++)
        {
            if (vis[mp[node][i]])
                continue;
            cnt += dfs(mp, mp[node][i], vis);
        }
        return cnt;
    }

public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> mp(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            mp[a].push_back(b);
            mp[b].push_back(a);
        }

        vector<bool> vis(n, false);
        long long ans = 0;
        long long cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;
            long long x = dfs(mp, i, vis);
            ans += cnt * x;
            cnt += x;
        }
        return ans;
    }
};