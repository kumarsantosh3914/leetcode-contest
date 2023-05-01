class Solution
{
public:
    long long countOperationsToEmptyArray(vector<int> &nums)
    {
        unordered_map<int, int> position;
        long long n = nums.size();
        long long ans = n;
        for (int i = 0; i < nums.size(); i++)
        {
            position[nums[i]] = i;
        }
        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++)
        {
            if (position[nums[i]] < position[nums[i - 1]])
            {
                ans += n - i;
            }
        }
        return ans;
    }
};