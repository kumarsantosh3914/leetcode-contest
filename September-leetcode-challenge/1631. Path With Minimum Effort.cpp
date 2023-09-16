class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // Create a min-heap priority queue to store efforts along with corresponding positions
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        // Initialize a 2D array to store minimum efforts to reach each position
        vector<vector<int>> dist(n, vector<int>(m, 1e9)); // Initialize with a large value
        dist[0][0] = 0; // Effort to reach the starting position is 0
        pq.push({0, {0, 0}}); // Push the starting position into the priority queue
        
        // Arrays to represent possible moves: up, right, down, left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while (!pq.empty()) {
            auto it = pq.top(); // Extract the position with the least effort
            pq.pop();

            int diff = it.first; // Effort required to reach the current position
            int row = it.second.first; // Row index of the current position
            int col = it.second.second; // Column index of the current position

            // If the current position is the destination, return the effort
            if (row == n - 1 && col == m - 1) {
                return diff;
            }

            // Explore possible moves (up, right, down, left) from the current position
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i]; // New row index after the move
                int ncol = col + dc[i]; // New column index after the move

                // Check if the new position is within the bounds of the grid
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    // Calculate the effort to reach the new position
                    int newEffort = max(diff, abs(heights[row][col] - heights[nrow][ncol]));

                    // If the new effort is smaller than the current recorded effort for the new position
                    if (newEffort < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newEffort; // Update the recorded effort
                        pq.push({newEffort, {nrow, ncol}}); // Push the new position and effort into the priority queue
                    }
                }
            }
        }
        return 0; 
    }
};
