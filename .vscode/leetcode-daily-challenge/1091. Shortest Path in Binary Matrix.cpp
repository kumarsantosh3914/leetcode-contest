class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> path(n, vector<int>(m, 0));
        path = grid;

        if (grid[0][0] == 1)
            return -1;
        path[0][0] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (i == n - 1 && j == m - 1)
                return path[i][j];

            int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

            for (int dir = 0; dir < 8; dir++)
            {
                int newi = i + dx[dir];
                int newj = j + dy[dir];

                if (newi >= 0 && newi < n && newj >= 0 && newj < m && path[newi][newj] == 0)
                {
                    q.push({newi, newj});
                    path[newi][newj] = 1 + path[i][j];
                    if (newi == n - 1 && newj == m - 1)
                        return path[newi][newj];
                }
            }
        }
        return -1;
    }
};