class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> row(rowIndex + 1);

        for (int i = 0; i < rowIndex + 1; i++)
        {

            row[i].resize(i + 1);
            row[i][0] = row[i][i] = 1;

            for (int j = 1; j < i; j++)
            {
                row[i][j] = row[i - 1][j - 1] + row[i - 1][j];
            }
        }
        return row[rowIndex];
    }
};