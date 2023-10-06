class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int nums1 = 0, nums2 = 0, cnt1 = 0, cnt2 = 0;
        int i;
        for (i = 0; i < n; i++)
        {
            if (nums1 == nums[i])
                cnt1++;
            else if (nums2 == nums[i])
                cnt2++;
            else if (cnt1 == 0)
            {
                nums1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                nums2 = nums[i];
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1 = cnt2 = 0;
        for (i = 0; i < n; i++)
        {
            if (nums1 == nums[i])
            {
                cnt1++;
            }
            else if (nums2 == nums[i])
            {
                cnt2++;
            }
        }
        if (cnt1 > n / 3)
        {
            ans.push_back(nums1);
        }
        if (cnt2 > n / 3)
        {
            ans.push_back(nums2);
        }
        return ans;
    }
};