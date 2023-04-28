class Solution
{
public:
    int numSimilarGroups(vector<string> &strs)
    {
        int groups = 0, n = strs.size();
        vector<bool> vis(n, false);
        for (int i = 0; i < strs.size(); i++)
        {
            if (vis[i])
                continue;
            groups++;
            dfs(i, strs, vis);
        }
        return groups;
    }

    void dfs(int i, vector<string> &strs, vector<bool> &vis)
    {
        vis[i] = true;
        for (int j = 0; j < strs.size(); j++)
        {
            if (vis[j])
                continue;
            if (is_similar(strs[i], strs[j]))
            {
                dfs(j, strs, vis);
            }
        }
    }

    bool is_similar(string a, string b)
    {
        int count = 0;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != b[i])
                count++;
        }
        return (count == 2 || count == 0);
    }
};