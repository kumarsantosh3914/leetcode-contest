class Solution {
private:
    int spanningTree(int V, vector<pair<int,int>> adj[]) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(V, 0);
        
        //{wt, node}
        pq.push({0, 0});
        int sum = 0;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            
            if(vis[node] == 1) continue;
            //add it to the mst
            vis[node] = 1;
            sum += wt;
            for(auto it:adj[node]) {
                int adjNode = it.first;
                int edW = it.second;
                if(!vis[adjNode]) {
                    pq.push({edW, adjNode});
                }
            }
        }
        return sum;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int>> adj[n];
        for(int i=0; i<n; i++) {
            for(int j=i + 1; j<n; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dis = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({j, dis});
                adj[j].push_back({i, dis});
            }
        }
        return spanningTree(n, adj);
    }
};