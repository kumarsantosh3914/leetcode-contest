class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 0));
        vector<vector<int>> vis(n, vector<int> (m, 0));
        // {{row, col}, distance}
        queue<pair<pair<int, int>, int>> pq;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    pq.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
                else {
                    vis[i][j] = 0;
                }
            }
        }
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        while(!pq.empty()) {
            int r = pq.front().first.first;
            int c = pq.front().first.second;
            int distance = pq.front().second;
            pq.pop();
            
            dist[r][c] = distance;
            for(int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && 
                   vis[nrow][ncol] == 0 && mat[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1;
                    pq.push({{nrow, ncol}, distance + 1});
                }
            }
        }
        return dist;
    }
};