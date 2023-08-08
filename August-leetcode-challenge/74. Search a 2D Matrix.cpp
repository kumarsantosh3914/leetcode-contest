class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int x) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i = 0, j = m-1;
        while(i < n && j >= 0) {
            if(matrix[i][j] == x) return true;
            else if(matrix[i][j] < x) {
                i++;
            }
            else {
                j--;
            }
        }
        return false;
    }
};