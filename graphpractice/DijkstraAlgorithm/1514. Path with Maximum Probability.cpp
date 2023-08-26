class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Create a graph representation using adjacency list
        unordered_map<int, vector<pair<int, double>> > adj;
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }
        
        // Array to store the maximum probability for each node
        vector<double> dist(n, 0);
        // Queue for the breadth-first search
        priority_queue<pair<double,int>> pq;
        // Add the starting node to the queue and set its probability to 1
        pq.push({1.0, start});
        dist[start] = 1;
        
        while (!pq.empty()){
            double dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
    
            // Traverse through each child node of the current node
            for (auto it : adj[node]){
                double edgeWeight = it.second;
                int adjNode = it.first;

                if(dis * edgeWeight > dist[adjNode]) {
                    dist[adjNode] = dis * edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        // Return the maximum probability of reaching the end node from the start node
        return dist[end];
    }
};