class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        string temp = "";

        for (int i = 0; i < nums.size(); i++)
        {
            int j = i;
            while (j + 1 < nums.size() && nums[j + 1] == nums[j] + 1)
                j++;
            if (j > i)
            {
                temp += to_string(nums[i]);
                temp += "->";
                temp += to_string(nums[j]);
            }
            else
            {
                temp += to_string(nums[i]);
            }
            ans.push_back(temp);
            temp = "";
            i = j;
        }
        return ans;
    }
};