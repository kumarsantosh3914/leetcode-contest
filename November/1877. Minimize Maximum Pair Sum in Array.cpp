class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = n - 1;
        int maxi = INT_MIN;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum > maxi)
            {
                maxi = sum;
            }
            left++;
            right--;
        }
        return maxi;
    }
};
