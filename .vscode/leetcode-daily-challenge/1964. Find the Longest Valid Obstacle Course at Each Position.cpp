class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        vector<int> ans;
        vector<int> dp;
        for (int i = 0; i < obstacles.size(); i++)
        {
            int length = lower_bound(dp.begin(), dp.end(), obstacles[i] + 1) - dp.begin();
            if (length == dp.size())
            {
                dp.push_back(obstacles[i]);
            }
            else
            {
                dp[length] = obstacles[i];
            }
            ans.push_back(length + 1);
        }
        return ans;
    }
};
