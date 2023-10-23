class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = k;
        int j = k;
        int curMini = nums[k];
        int ans = nums[k];

        while (i > 0 || j < n - 1)
        {
            int leftValue = (i > 0) ? nums[i - 1] : 0;
            int rightValue = (j < n - 1) ? nums[j + 1] : 0;

            if (leftValue < rightValue)
            {
                j++;
                curMini = min(curMini, nums[j]);
            }
            else
            {
                i--;
                curMini = min(curMini, nums[i]);
            }

            ans = max(ans, curMini * (j - i + 1));
        }
        return ans;
    }
};