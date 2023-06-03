class Solution
{
private:
    unordered_map<int, vector<int>> ump;
    int ans = 0;
    int maxi = 0;
    void dfs(int manager, vector<int> &informTime)
    {
        maxi = max(ans, maxi);
        for (auto it : ump[manager])
        {
            ans += informTime[manager];
            dfs(it, informTime);
            ans -= informTime[manager];
        }
    }

public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        for (int i = 0; i < n; i++)
        {
            int val = manager[i];
            if (val != -1)
            {
                ump[val].push_back(i);
            }
        }
        dfs(headID, informTime);
        return maxi;
    }
};