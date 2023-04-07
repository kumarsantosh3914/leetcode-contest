class Solution
{
private:
    int count(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }

private:
    bool isValid(int i, int j, int n, int m, vector<vector<int>> &grid)
    {
        if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1)
        {
            return true;
        }
        return false;
    }

private:
    void dfs(int i, int j, int n, int m, vector<vector<int>> &grid)
    {
        grid[i][j] = 0;
        if (isValid(i + 1, j, n, m, grid))
        {
            dfs(i + 1, j, n, m, grid);
        }
        if (isValid(i - 1, j, n, m, grid))
        {
            dfs(i - 1, j, n, m, grid);
        }
        if (isValid(i, j + 1, n, m, grid))
        {
            dfs(i, j + 1, n, m, grid);
        }
        if (isValid(i, j - 1, n, m, grid))
        {
            dfs(i, j - 1, n, m, grid);
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            // Left -> top to bottom
            int j = 0;
            if (grid[i][j] == 1)
            {
                dfs(i, j, n, m, grid);
            }

            // right -> top to bottom
            j = m - 1;
            if (grid[i][j] == 1)
            {
                dfs(i, j, n, m, grid);
            }
        }

        for (int j = 0; j < m; j++)
        {
            // top -> left to right
            int i = 0;
            if (grid[i][j] == 1)
            {
                dfs(i, j, n, m, grid);
            }

            // bottom -> right to left
            i = n - 1;
            if (grid[i][j] == 1)
            {
                dfs(i, j, n, m, grid);
            }
        }

        return count(grid);
    }
};