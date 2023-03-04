#define ll long long
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        int minFound = 0, maxFound = 0;
        int start = 0, minStart = 0, maxStart = 0;
        ll ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minK || nums[i] > maxK)
            {
                minFound = 0;
                maxFound = 0;
                start = i + 1;
            }
            if (nums[i] == minK)
            {
                minFound = 1;
                minStart = i;
            }
            if (nums[i] == maxK)
            {
                maxFound = 1;
                maxStart = i;
            }
            if (minFound && maxFound)
            {
                ans += (min(minStart, maxStart) - start + 1);
            }
        }
        return ans;
    }
};