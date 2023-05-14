class Solution
{
private:
    int solve(vector<int> &nums, unordered_map<vector<bool>, int> &mp, vector<bool> &visited, int opr)
    {
        if (mp.count(visited))
            return mp[visited];

        int maxScore = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (visited[i])
                continue;

            for (int j = i + 1; j < nums.size(); j++)
            {
                if (visited[j])
                    continue;
                visited[i] = true;
                visited[j] = true;

                int curScore = opr * __gcd(nums[i], nums[j]);
                int nextMaxScore = solve(nums, mp, visited, opr + 1);
                int totalScore = curScore + nextMaxScore;
                maxScore = max(maxScore, totalScore);

                visited[i] = false;
                visited[j] = false;
            }
        }
        return mp[visited] = maxScore;
    }

public:
    int maxScore(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> visited(n, false);
        unordered_map<vector<bool>, int> mp;
        int res = solve(nums, mp, visited, 1);
        return res;
    }
};