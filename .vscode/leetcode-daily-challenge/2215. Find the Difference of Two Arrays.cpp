class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> mp, up;

        for (auto it : nums1)
            mp[it]++;
        for (auto it : nums2)
            up[it]++;

        vector<vector<int>> ans;

        vector<int> vec;

        for (auto it : mp)
        {
            if (up.find(it.first) == up.end())
                vec.push_back(it.first);
        }

        ans.push_back(vec);

        vec.clear();

        for (auto it : up)
        {
            if (mp.find(it.first) == mp.end())
                vec.push_back(it.first);
        }

        ans.push_back(vec);
        return ans;
    }
};