class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        long maxi = 0;
        long sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            maxi = max(maxi, (sum + i) / (i + 1));
        }
        return maxi;
    }
};