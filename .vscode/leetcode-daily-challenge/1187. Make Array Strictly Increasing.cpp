class Solution
{
private:
    int helper(int i, int prev, vector<int> &arr1, vector<int> &arr2, map<pair<int, int>, int> &dp)
    {
        if (i == arr1.size())
            return 0;

        if (dp.find({i, prev}) != dp.end())
            return dp[{i, prev}];

        int index = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();

        int ans = 2001;

        if (arr1[i] > prev)
        {
            ans = min(ans, helper(i + 1, arr1[i], arr1, arr2, dp));
        }

        if (index < arr2.size())
        {
            ans = min(ans, helper(i + 1, arr2[index], arr1, arr2, dp) + 1);
        }

        return dp[{i, prev}] = ans;
    }

public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        sort(arr2.begin(), arr2.end());
        map<pair<int, int>, int> dp;
        int ans = helper(0, -1, arr1, arr2, dp);
        if (ans >= 2001)
            return -1;
        return ans;
    }
};
