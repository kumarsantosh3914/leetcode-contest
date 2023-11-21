class Solution
{
public:
    int reverse(int num)
    {
        int num2 = 0;
        while (num > 0)
        {
            int d = num % 10;
            num /= 10;
            num2 = num2 * 10 + d;
        }
        return num2;
    }
    int countNicePairs(vector<int> &nums)
    {
        const int mod = 1e9 + 7;
        unordered_map<int, int> ump;
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] - reverse(nums[i]);
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ans = (ans + ump[nums[i]]) % mod;
            ump[nums[i]]++;
        }
        return ans;
    }
};