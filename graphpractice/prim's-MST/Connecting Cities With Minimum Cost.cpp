#include <bits/stdc++.h> 

int spanningTree(int V, vector<pair<int,int>> adj[]) {
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> vis(V + 1, 0);
        
    //{wt, node}
    pq.push({0, 1});
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
	for(int i=1; i<=V; i++) {
		if(vis[i] == 0) return -1;
	}
    return sum;
}

int getMinimumCost(int n, int m, vector<vector<int>> &connections)
{
	vector<pair<int,int>> adj[n + 1];
	for(int i=0; i<m; i++) {
		int u = connections[i][0];
		int v = connections[i][1];
		int wt = connections[i][2];

		adj[u].push_back({v, wt});
		adj[v].push_back({u, wt});
	}
	return spanningTree(n, adj);
}