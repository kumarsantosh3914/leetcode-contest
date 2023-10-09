class Solution
{
private:
    int dp[501][501][2];
    int helper(int i, int j, vector<int> &nums1, vector<int> &nums2, int l)
    {
        if (i == nums1.size() || j == nums2.size())
        {
            if (l == 1)
                return 0;
            else
                return -1;
        }
        if (dp[i][j][l] != INT_MIN)
            return dp[i][j][l];
        else
        {
            int op1 = nums1[i] * nums2[j] + helper(i + 1, j + 1, nums1, nums2, 1);
            int op2 = helper(i + 1, j, nums1, nums2, l);
            int op3 = helper(i, j + 1, nums1, nums2, l);
            return dp[i][j][l] = max(op1, max(op2, op3));
        }
    }

public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                dp[i][j][0] = INT_MIN;
                dp[i][j][1] = INT_MIN;
            }
        }
        int ans = helper(0, 0, nums1, nums2, 0);
        if (ans == -1)
        {
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            return max(nums1.front() * nums2.back(), nums2.front() * nums1.back());
        }
        return ans;
    }
};