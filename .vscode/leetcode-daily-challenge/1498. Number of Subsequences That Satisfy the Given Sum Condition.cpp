#define mod 1000000007
class Solution
{
private:
    long helper(int x, int y)
    {
        if (y == 1)
            return x;
        if (y == 0)
            return 1;
        long ans = 1;
        if (y % 2 == 0)
        {
            ans = helper(x, y / 2);
            ans *= ans;
        }
        else
        {
            ans = helper(x, y - 1);
            ans *= x;
        }
        return ans % mod;
    }

public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;
        int ans = 0;
        while (start <= end)
        {
            if (nums[start] + nums[end] <= target)
            {
                ans += (helper(2, end - start));
                ans %= mod;
                start++;
            }
            else
            {
                end--;
            }
        }
        return ans;
    }
};