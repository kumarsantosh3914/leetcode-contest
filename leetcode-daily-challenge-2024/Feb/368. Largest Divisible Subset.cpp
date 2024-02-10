class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(begin(nums), end(nums));

        int n = size(nums), max_i = 0; // Get the size of nums and initialize max_i to keep track of the index where the largest subset ends.
        // dp[i]=1 since we can always form subset of size=1 ending at i.
        // pred[i]=-1 because we haven't found any predecessors for any subset yet.
        vector<int> dp(n, 1), pred(n, -1), ans;

        // Iterate through each element of nums starting from the second one.
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                // nums[i] should divide nums[j] if it is to be included in its subset (i.e dp[j])
                // Only include nums[i] in subset ending at j if resultant subset size (dp[j]+1) is larger than already possible (dp[i])
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1, pred[i] = j; // jth element will be predecessor to subset ending at ith element
            }
            if (dp[i] > dp[max_i])
                max_i = i; // Keep track of index where the largest subset ends
        }

        // Reconstruct the largest divisible subset by starting with the index where the largest subset ended and moving backward.
        for (; max_i >= 0; max_i = pred[max_i])
            ans.push_back(nums[max_i]);

        return ans;
    }
};
