class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int sum = 0, maxLen = 0;
        unordered_map<int, int> ump{{0, -1}};

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 1 ? 1 : -1;
            if (ump.count(sum))
                maxLen = max(maxLen, i - ump[sum]);
            else
                ump[sum] = i;
        }
        return maxLen;
    }
};