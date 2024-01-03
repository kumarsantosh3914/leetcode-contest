class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto it : nums)
            mp[it]++;
        int rowCount = 0;
        for (auto &it : mp)
        {
            rowCount = max(rowCount, it.second);
        }

        vector<vector<int>> ans(rowCount);
        for (auto it : mp)
        {
            int d = 0;
            while (it.second--)
            {
                ans[d++].push_back(it.first);
            }
        }
        return ans;
    }
};
