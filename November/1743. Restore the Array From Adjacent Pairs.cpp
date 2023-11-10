class Solution
{
private:
    void dfs(unordered_map<int, vector<int>> &adj, int node, set<int> &st, vector<int> &ans)
    {
        if (st.find(node) != st.end())
            return;
        ans.push_back(node);
        st.insert(node);
        for (auto &it : adj[node])
        {
            dfs(adj, it, st, ans);
        }
    }

public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        unordered_map<int, vector<int>> adj;
        for (auto &it : adjacentPairs)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int head;
        for (auto &it : adj)
        {
            if (it.second.size() == 1)
                head = it.first;
        }
        set<int> st;
        vector<int> ans;
        dfs(adj, head, st, ans);
        return ans;
    }
};