class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        // idea: for a group of continuous same characters,
        // we need to delete all the group but leave only one character
        // for each group of continuous same characters,
        // we need cost = sumCost(group) - maxCost(group)
        int ans = 0;
        int maxCost = 0;
        for (int i = 0; i < colors.size(); i++)
        {
            if (i > 0 && colors[i] != colors[i - 1])
            {
                maxCost = 0;
            }
            ans += min(maxCost, neededTime[i]);
            maxCost = max(maxCost, neededTime[i]);
        }
        return ans;
    }
};
