class Solution
{
private:
    void dfs(int row, int col, vector<vector<char>> &grid, int delrow[], int delcol[])
    {
        grid[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1')
            {
                dfs(nrow, ncol, grid, delrow, delcol);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(i, j, grid, delrow, delcol);
                }
            }
        }
        return count;
    }
};