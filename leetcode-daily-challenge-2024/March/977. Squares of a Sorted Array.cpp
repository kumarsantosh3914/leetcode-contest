class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> res(nums.size());
        int l = 0, r = nums.size() - 1;
        for (int k = nums.size() - 1; k >= 0; k--)
        {
            if (abs(nums[r]) > abs(nums[l]))
                res[k] = nums[r] * nums[r--];
            else
                res[k] = nums[l] * nums[l++];
        }
        return res;
    }
};