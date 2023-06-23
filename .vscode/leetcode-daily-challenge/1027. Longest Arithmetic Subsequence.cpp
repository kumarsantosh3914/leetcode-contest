int longestArithSeqLength(vector<int> &nums)
{

    // If the size of the vector is 2 or less, the length of the longest arithmetic sequence cannot be greater than the size of the vector itself.
    if (nums.size() <= 2)
        return nums.size();
    // Initialize the answer variable to 0.
    int ans = 0;

    // Create a dynamic programming table (a 2D unordered map), where dp[i][diff] represents the length of the arithmetic sequence that ends with nums[i], with a common difference of 'diff'.
    unordered_map<int, int> dp[nums.size() + 1];

    // Iterate over the vector (except for the first element since we can't form an arithmetic sequence with just one element).
    for (int i = 1; i < nums.size(); i++)
    {
        // For each element, iterate through all the previous elements (j), and calculate the difference 'diff' between them.
        for (int j = 0; j < i; j++)
        {
            int diff = nums[i] - nums[j];
            // If the difference exists in the dp table for element j, get its length.
            int count = 1;
            if (dp[j].count(diff))
                count = dp[j][diff];
            // Update the dp table for element i, and increase the length of the sequence by 1 (count + 1).
            dp[i][diff] = count + 1;
            // Update the answer variable with the maximum length calculated so far.
            ans = max(ans, dp[i][diff]);
        }
    }
    // Return the answer.
    return ans;
}