class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int maxi_c = 0;
        vector<bool> ans;
        for (auto a : candies)
            maxi_c = max(maxi_c, a);
        for (auto a : candies)
        {
            if (a + extraCandies >= maxi_c)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};