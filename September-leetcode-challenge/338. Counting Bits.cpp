class Solution {
public:
    vector<int> countBits(int n) {
        // Create a vector to store the count of set bits (1s) for each number from 0 to n.
        vector<int> dp(n + 1);
        // Initialize the count of set bits for 0 as 0 (no set bits).
        dp[0] = 0;
        // Loop through numbers from 1 to n.
        for(int i = 1; i <= n; i++) {
            // Calculate the highest power of 2, x, that is less than or equal to i.
            int x = log2(i);

            // Use the previously computed count for i - 2^x to find the count for i.
            // Essentially, we are reusing the count of set bits for a smaller number (i - 2^x)
            // and adding 1 to it, because we are considering the rightmost set bit in i.
            dp[i] = 1 + dp[i - (1 << x)];
        }
        // Return the vector containing the count of set bits for numbers from 0 to n.
        return dp;
    }
};
