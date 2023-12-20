class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size(), n = img[0].size();
        if (m == 0 || n == 0)
            return {{}};
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = img[i][j], cnt = 1;
                for (int k = 0; k < dirs.size(); k++)
                {
                    int x = i + dirs[k][0], y = j + dirs[k][1];
                    if (x < 0 || x > m - 1 || y < 0 || y > n - 1)
                        continue;
                    sum += (img[x][y] & 0xFF);
                    cnt++;
                }
                img[i][j] |= ((sum / cnt) << 8);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                img[i][j] >>= 8;
            }
        }
        return img;
    }
};