class Solution
{
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int sum = 0;
        for (auto &it : nums)
        {
            sum += it;
        }
        int n = nums.size();
        vector<int> ans(n);
        int left_sum = 0, left_num = 0;
        for (int i = 0; i < n; i++)
        {
            int right_sum = sum - left_sum - nums[i];
            int right_num = n - 1 - left_num;
            ans[i] = (left_num * nums[i] - left_sum) + (right_sum - right_num * nums[i]);
            left_num++;
            left_sum += nums[i];
        }
        return ans;
    }
};