class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> ump;
        for (auto &it : arr)
        {
            ump[it]++;
        }

        vector<int> nums;
        for (const auto &it : ump)
        {
            nums.push_back(it.second);
        }

        int ans = ump.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (k == 0 || k < nums[i])
                return ans;
            k -= nums[i];
            ans--;
        }
        return ans;
    }
};

/*
ump
1 - 2
2 - 1
3 - 3
4 - 1

vec - 1 1 2 3
ans = 2

k = 1
(k == 0 x || k < 1 x )

*/
