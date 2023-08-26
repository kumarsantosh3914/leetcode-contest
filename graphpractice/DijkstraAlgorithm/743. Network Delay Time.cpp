class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>> > adj;
        for(auto it: times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // Initialize a vector to store the shortest distances from the source node
        vector<int> dist(n + 1);
        
        // Initialize distances to a large value (representing infinity) except for the source node
        for (int i = 0; i <= n; i++) {
            dist[i] = 1e9;  // This value can be considered as infinity
        }
        dist[k] = 0;  // Distance to the source node is 0
        pq.push({0, k});  // Push the source node into the priority queue with distance 0
        
        // Main loop of Dijkstra's algorithm
        while (!pq.empty()) {
            int dis = pq.top().first;    // Current shortest distance to a node
            int node = pq.top().second;   // Current node
            pq.pop();  // Remove the current node from the priority queue

            // Explore all neighboring nodes of the current node
            for (auto it : adj[node]) {
                int edgeWeight = it.second;    // Weight of the edge to the neighboring node
                int adjNode = it.first;       // Neighboring node index

                // If the path through the current node is shorter, update the distance
                if (dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;  // Update the shortest distance
                    pq.push({dist[adjNode], adjNode}); // Push the updated distance and node into the priority queue
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1; i<=n; i++) {
            ans = max(ans, dist[i]);
        }
        return ans == 1e9 ? -1 : ans;
    }
};
