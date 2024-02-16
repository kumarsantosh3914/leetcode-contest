class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<long long> prefixSum;
        long long sum = 0;
        for (auto &it : nums)
        {
            prefixSum.push_back(sum);
            sum += it;
        }

        int n = nums.size();
        for (int i = n - 1; i >= 2; i--)
        {
            if (nums[i] < prefixSum[i])
            {
                return (long long)(prefixSum[i] + nums[i]);
            }
        }
        return -1;
    }
};