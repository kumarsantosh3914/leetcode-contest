class Solution
{
private:
    long long helper(int index, vector<vector<int>> &questions, vector<long long> &dp)
    {
        // base case
        if (index >= questions.size())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        // take it
        long long take = questions[index][0] + helper(index + questions[index][1] + 1, questions, dp);
        long long skip = helper(index + 1, questions, dp);

        return dp[index] = max(take, skip);
    }

public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        vector<long long> dp(questions.size(), -1);
        return helper(0, questions, dp);
    }
};