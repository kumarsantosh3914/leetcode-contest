class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> ump;
        for (auto &it : nums)
        {
            ump[it]++;
        }

        int maxi = 0;
        for (auto &it : ump)
        {
            maxi = max(maxi, it.second);
        }
        // cout << maxi << endl;

        int ans = 0;
        for (auto &it : ump)
        {
            if (it.second == maxi)
            {
                ans += maxi;
            }
        }
        return ans;
    }
};