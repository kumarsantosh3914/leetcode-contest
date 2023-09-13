class Solution {
private:
    // The 'solve' function is a recursive helper function to calculate
    // the minimum initial health needed for a knight to reach the bottom-right
    // cell of the dungeon from a given position (i, j).
    int solve(int i, int j, vector<vector<int>>& dungeon, vector<vector<int>> &dp) {
        // Base case: If we go out of bounds, return a large value (infinite) 
        // to indicate that this path is not valid.
        if (i == dungeon.size() || j == dungeon[0].size()) {
            return 1e9; // A very large value, effectively representing infinity.
        }

        // If we have already calculated the minimum health needed for this position,
        // return it from the 'dp' array to avoid redundant calculations.
        if (dp[i][j] != -1) return dp[i][j];

        // If we are at the bottom-right cell, calculate the minimum health needed
        // to reach this cell based on the cell's value (positive or negative).
        if (i == dungeon.size() - 1 && j == dungeon[0].size() - 1) {
            // If the cell has a negative value, we need to gain health to reach it.
            // If it's positive or zero, we only need 1 health to reach it.
            return dp[i][j] = (dungeon[i][j] <= 0) ? -dungeon[i][j] + 1 : 1;
        }

        // Calculate the minimum height required to reach the bottom-right cell
        // from the current cell. We choose the path with the minimum height.
        int minHeightRequired = min(solve(i + 1, j, dungeon, dp), solve(i, j + 1, dungeon, dp)) - dungeon[i][j];
        
        // The minimum height required can't be negative, so if it's less than or
        // equal to 0, set it to 1 (minimum health needed).
        return dp[i][j] = (minHeightRequired <= 0) ? 1 : minHeightRequired; 
    }
public:
    // The 'calculateMinimumHP' function is the entry point for solving the problem.
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // Initialize a 2D DP array to store the results of subproblems.
        vector<vector<int>> dp(dungeon.size(), vector<int>(dungeon[0].size(), -1));
        // Start the recursive calculation from the top-left corner (0, 0).
        return solve(0, 0, dungeon, dp);
    }
};
