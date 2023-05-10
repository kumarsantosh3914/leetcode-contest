class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int left = 0, right = n - 1, top = 0, bottom = n - 1, nums = 1;
        while (left <= right && top <= bottom)
        {
            // left to top right
            for (int i = left; i <= bottom; i++)
            {
                matrix[top][i] = nums++;
            }
            top++;
            // top right to bottom right
            for (int i = top; i <= bottom; i++)
            {
                matrix[i][right] = nums++;
            }
            right--;
            // bottom right to bottom left
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                {
                    matrix[bottom][i] = nums++;
                }
                bottom--;
            }
            // bottom left to top left
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    matrix[i][left] = nums++;
                }
                left++;
            }
        }
        return matrix;
    }
};
