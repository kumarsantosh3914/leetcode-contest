class Solution
{
private:
    int maxLength = -1;
    void cycle(vector<int> &edges, int ind, vector<bool> &vis, vector<int> &store)
    {
        if (ind == -1)
            return;
        if (vis[ind])
        {
            int cnt = -1;
            for (int i = 0; i < store.size(); i++)
            {
                if (store[i] == ind)
                {
                    cnt = i;
                    break;
                }
            }
            if (cnt == -1)
                return;
            int size = (store.size() - cnt);
            maxLength = max(maxLength, size);
            return;
        }
        vis[ind] = true;
        store.push_back(ind);
        cycle(edges, edges[ind], vis, store);
        return;
    }

public:
    int longestCycle(vector<int> &edges)
    {
        vector<bool> visit(edges.size(), 0);

        for (int i = 0; i < edges.size(); i++)
        {
            if (visit[i])
                continue;
            vector<int> store;
            cycle(edges, i, visit, store);
        }
        return maxLength;
    }
};