#define ll long long
class Solution
{
private:
    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int &count, int i)
    {
        visited[i] = true;
        count++;

        for (int j = 0; j < graph[i].size(); j++)
        {
            if (!visited[graph[i][j]])
                dfs(graph, visited, count, graph[i][j]);
        }
    }

public:
    int maximumDetonation(vector<vector<int>> &bombs)
    {
        vector<vector<int>> graph(bombs.size());
        for (int i = 0; i < bombs.size(); i++)
        {
            ll x1, y1, r1;
            x1 = bombs[i][0];
            y1 = bombs[i][1];
            r1 = bombs[i][2];

            for (int j = 0; j < bombs.size(); j++)
            {
                if (i != j)
                {
                    ll x2, y2, r2;
                    x2 = abs(x1 - bombs[j][0]);
                    y2 = abs(y1 - bombs[j][1]);

                    if (x2 * x2 + y2 * y2 <= r1 * r1)
                    {
                        graph[i].push_back(j);
                    }
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < bombs.size(); i++)
        {
            int count = 0;
            vector<bool> visited(bombs.size(), false);
            dfs(graph, visited, count, i);
            ans = max(ans, count);
        }
        return ans;
    }
};