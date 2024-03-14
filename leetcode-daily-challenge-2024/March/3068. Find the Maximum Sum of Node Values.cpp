class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        typedef long long ll;
        ll sum1 = 0;
        ll sum2 = 0;
        int count = 0;

        for (auto &it : nums)
        {
            if ((it ^ k) > it)
            {
                sum1 += (it ^ k);
                count++;
            }
            else
            {
                sum2 += it;
            }
        }

        if (count % 2 == 0)
        {
            return sum1 + sum2;
        }

        ll maxi1 = 0;
        ll maxi2 = 0;
        for (auto &it : nums)
        {
            if ((it ^ k) > it)
            {
                maxi1 = max(maxi1, sum1 - (it ^ k) + sum2 + it);
            }
            else
            {
                maxi2 = max(maxi2, sum1 + (it ^ k) + sum2 - it);
            }
        }
        return max(maxi1, maxi2);
    }
};