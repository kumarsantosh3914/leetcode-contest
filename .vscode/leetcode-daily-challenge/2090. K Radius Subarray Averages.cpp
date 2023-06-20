class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        long long windowSize = 2 * k + 1, sum = 0;
        vector<int> ans(nums.size(), -1);
        // if the array too short to conver a window
        if (nums.size() < windowSize)
            return ans;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (i - windowSize >= 0)
                sum -= nums[i - windowSize];
            if (i >= windowSize - 1)
            {
                ans[i - k] = sum / windowSize;
            }
        }
        return ans;
    }
};