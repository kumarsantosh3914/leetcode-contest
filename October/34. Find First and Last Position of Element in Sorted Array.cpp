class Solution
{
private:
    int firstOcc(vector<int> &nums, int target)
    {
        int ans = 0;
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (target == nums[mid])
            {
                ans = mid;
                high = mid - 1;
            }
            else if (target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    // last occurence
    int lastOcc(vector<int> &nums, int target)
    {
        int ans = 0;
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (target == nums[mid])
            {
                ans = mid;
                low = mid + 1;
            }
            else if (target < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (!binary_search(nums.begin(), nums.end(), target))
            return {-1, -1};
        vector<int> ans;
        int f = firstOcc(nums, target);
        int l = lastOcc(nums, target);

        if (f == -1 || l == -1)
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(f);
            ans.push_back(l);
        }
        return ans;
    }
};