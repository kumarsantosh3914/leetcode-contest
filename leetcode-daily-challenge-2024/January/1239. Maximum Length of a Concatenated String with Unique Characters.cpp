class Solution
{
private:
    void helper(vector<string> &arr, vector<int> &nums, int ind, int &ans, int n)
    {
        // temparary ans
        int res = 0;
        for (int i = 0; i < 26; i++)
        {
            if (nums[i] > 1)
                return;
            if (nums[i] == 1)
                res++;
        }
        ans = max(ans, res);
        for (int i = ind; i < n; i++)
        {
            for (char ch : arr[i])
                nums[ch - 'a']++;
            helper(arr, nums, i + 1, ans, n);
            for (char ch : arr[i])
                nums[ch - 'a']--;
        }
    }

public:
    int maxLength(vector<string> &arr)
    {
        vector<int> nums(26, 0);
        int ans = 0;
        int n = arr.size();
        helper(arr, nums, 0, ans, n);
        return ans;
    }
};