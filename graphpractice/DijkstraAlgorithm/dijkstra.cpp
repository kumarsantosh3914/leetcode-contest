class Solution {
public:
    // Dijkstra's algorithm implementation to find shortest distances from a source node
    vector<int> dijkstra(int v, vector<vector<int>> adj[], int src) {
        // Create a min-heap priority queue to store nodes with their distances
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Initialize a vector to store the shortest distances from the source node
        vector<int> dist(v);
        
        // Initialize distances to a large value (representing infinity) except for the source node
        for (int i = 0; i < v; i++) {
            dist[i] = 1e9;  // This value can be considered as infinity
        }
        dist[src] = 0;  // Distance to the source node is 0
        pq.push({0, src});  // Push the source node into the priority queue with distance 0
        
        // Main loop of Dijkstra's algorithm
        while (!pq.empty()) {
            int dis = pq.top().first;    // Current shortest distance to a node
            int node = pq.top().second;   // Current node
            pq.pop();  // Remove the current node from the priority queue

            // Explore all neighboring nodes of the current node
            for (auto it : adj[node]) {
                int edgeWeight = it[1];    // Weight of the edge to the neighboring node
                int adjNode = it[0];       // Neighboring node index

                // If the path through the current node is shorter, update the distance
                if (dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;  // Update the shortest distance
                    pq.push({dist[adjNode], adjNode}); // Push the updated distance and node into the priority queue
                }
            }
        }
        return dist;  // Return the vector of shortest distances from the source node
    }
};
