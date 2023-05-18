class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> nums(n, 0);
        for (auto &it : edges)
        {
            nums[it[1]]++;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};