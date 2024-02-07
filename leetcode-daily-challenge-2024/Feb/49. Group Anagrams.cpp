class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < strs.size(); i++)
        {
            auto s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }

        vector<vector<string>> ans;
        for (const auto a : mp)
        {
            vector<string> v;
            for (const auto it : a.second)
            {
                v.push_back(strs[it]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};