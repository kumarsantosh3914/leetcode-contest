class Solution
{
private:
    unordered_map<string, int> dp;
    int helper(int prev, int idx, vector<int> &nums, int k)
    {
        if (idx >= nums.size())
            return 0;

        string key = to_string(prev) + "-" + to_string(idx);
        if (dp.find(key) != dp.end())
            return dp[key];

        int ans = 0;
        if (prev == -1 || idx - prev <= k)
        {
            int take = nums[idx] + helper(idx, idx + 1, nums, k);
            int notTake = helper(prev, idx + 1, nums, k);

            ans = max(take, notTake);
        }
        return ans;
    }

public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> t(n, 0);
        t = nums;
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        pq.push({t[0], 0});
        int maxi = t[0];

        for (int i = 1; i < n; i++)
        {
            while (!pq.empty() && pq.top().second < i - k)
            {
                pq.pop();
            }

            t[i] = max(t[i], nums[i] + pq.top().first);
            pq.push({t[i], i});
            maxi = max(maxi, t[i]);
        }
        return maxi;
    }
};