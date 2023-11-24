class Solution
{
private:
    bool check(vector<int> &num)
    {
        sort(num.begin(), num.end());

        int n = num.size();
        int diff = num[1] - num[0];
        for (int i = 2; i < n; i++)
        {
            if (num[i] - num[i - 1] != diff)
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        int m = l.size();
        vector<bool> ans;
        for (int i = 0; i < m; i++)
        {
            int start = l[i];
            int end = r[i];

            vector<int> num(nums.begin() + start, nums.begin() + end + 1);
            ans.push_back(check(num));
        }
        return ans;
    }
};