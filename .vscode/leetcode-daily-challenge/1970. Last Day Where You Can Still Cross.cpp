class Solution {
private:
    int drow[4] = {0, 0, -1, 1}; // Array to store change in row indices for each of the four directions (up, down, left, right)
    int dcol[4] = {1, -1, 0, 0}; // Array to store change in column indices for each of the four directions (up, down, left, right)

    // Function to check if it is possible to walk to the last row given the current state of cells
    bool canWalk(vector<vector<int>> &cells, int row, int col, int dayAt) {
        vector<vector<bool>> grid(row + 1, vector<bool> (col + 1, 0));

        // Mark cells that are present until dayAt as visited
        for(int i=0; i<dayAt; i++) {
            grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }

        queue<pair<int, int>> q;

        // Start from the first row and add all unvisited cells in the first row to the queue
        for(int c=0; c<col; c++) {
            // If the cell is not visited, mark it as visited and add it to the queue
            if(grid[0][c] == 0) {
                q.push({0, c});
                grid[0][c] = 1;
            }
        }

        while(!q.empty()) {
            int r = q.front().first; // Get the row index of the cell from the front of the queue
            int c = q.front().second; // Get the column index of the cell from the front of the queue
            q.pop();

            // If we have reached the last row, return true (it is possible to cross)
            if(r == row - 1) return true;

            // Check all four directions (up, down, left, right) to see if we can move to a neighboring cell
            for(int i=0; i<4; i++) {
                int nrow = r + drow[i]; // Calculate the new row index for the neighboring cell
                int ncol = c + dcol[i]; // Calculate the new column index for the neighboring cell

                // If the new row or column index is out of bounds or the neighboring cell is already visited, skip to the next direction
                if(nrow < 0 || ncol < 0 || nrow == row || ncol == col || grid[nrow][ncol] == 1) continue;

                // Mark the neighboring cell as visited and add it to the queue
                grid[nrow][ncol] = 1;
                q.push({nrow, ncol});
            } 
        }
        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int start = 1, end = cells.size(); // Start and end indices for binary search
        int ans = 0; 

        // Perform binary search to find the latest day when it is possible to cross
        while(start <= end) {
            int mid = start + (end - start)/2; // Calculate the middle day
            if(canWalk(cells, row, col, mid)) {
                ans = mid; // If it is possible to cross on this day, update the answer
                start = mid + 1; // Move the start index to the right to try finding a later day
            }
            else {
                end = mid - 1; // If it is not possible to cross on this day, move the end index to the left
            }
        }
        return ans;
    }
};