class Solution
{
private:
    int dfs(vector<vector<int>> &grid, int row, int col)
    {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0)
            return 0;

        int fish = grid[row][col];
        grid[row][col] = 0;

        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto d : directions)
        {
            fish += dfs(grid, row + d[0], col + d[1]);
        }
        return fish;
    }

public:
    int findMaxFish(vector<vector<int>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};