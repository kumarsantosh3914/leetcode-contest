class Solution
{
public:
    vector<int> colorTheArray(int n, vector<vector<int>> &queries)
    {
        vector<int> nums(n, 0), ans;
        int count = 0;
        for (auto &it : queries)
        {
            int i = it[0], value = it[1];
            // CHECK CONTRIBUTIONS BEFORE COLORING WITH NEW COLOR
            if (nums[i] && i - 1 >= 0 && nums[i - 1] == nums[i])
                count--;
            if (nums[i] && i + 1 < n && nums[i + 1] == nums[i])
                count--;
            nums[i] = value;
            // CHECK CONTRIBUTIONS AFTER COLORING WITH NEW COLOR
            if (i - 1 >= 0 && nums[i - 1] == nums[i])
                count++;
            if (i + 1 < n && nums[i + 1] == nums[i])
                count++;
            ans.push_back(count);
        }
        return ans;
    }
};
