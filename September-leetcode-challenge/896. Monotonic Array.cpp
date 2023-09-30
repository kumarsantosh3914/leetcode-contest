class Solution
{
public:
    bool isMonotonic(vector<int> &nums)
    {
        bool isIncrease = true;
        bool isDecrease = true;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
                isIncrease = false;
            if (nums[i] < nums[i + 1])
                isDecrease = false;
            if (isIncrease == false && isDecrease == false)
                return false;
        }
        return true;
    }
};