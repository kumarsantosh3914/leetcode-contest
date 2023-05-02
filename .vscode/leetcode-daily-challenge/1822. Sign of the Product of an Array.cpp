class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int ngCount = 0, ind = 0;
        for (ind = 0; ind < nums.size(); ind++)
        {
            if (nums[ind] == 0)
                return 0;
            else if (nums[ind] <= 0)
                ngCount++;
        }
        if (ngCount % 2 == 0)
            return 1;
        else
            return -1;
    }
};