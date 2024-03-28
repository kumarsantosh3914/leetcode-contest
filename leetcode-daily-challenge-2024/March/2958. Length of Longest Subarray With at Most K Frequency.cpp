class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> ump;

        int left = 0, ans = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            ump[nums[right]]++;
            while (ump[nums[right]] > k)
            {
                ump[nums[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};