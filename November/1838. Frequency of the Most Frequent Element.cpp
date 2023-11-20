class Solution
{
private:
    int bs(vector<int> &nums, vector<long long> &sum, int k, int i)
    {
        long long low = 0, high = i, mid, ans;
        while (low <= high)
        {
            mid = (high - low) / 2 + low;
            // i - m + 1 = s (size of the window)
            long long lhs = (i - mid + 1) * nums[i], rhs;
            if (mid == 0)
            {
                rhs = sum[i] + k;
            }
            else
            {
                rhs = sum[i] - sum[mid - 1] + k;
            }
            if (lhs <= rhs)
            {
                ans = i - mid + 1;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }

public:
    int maxFrequency(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        long i = 0, j = 0;
        long count = 1;
        long sum = nums[0];
        for (; i < nums.size(); i++)
        {
            while (j < nums.size() && (j - i + 1) * nums[j] - sum <= k)
            {
                count = max(count, j - i + 1);
                j++;
                if (j < nums.size())
                {
                    sum += nums[j];
                }
            }
            sum -= nums[i];
        }
        return count;
    }
};