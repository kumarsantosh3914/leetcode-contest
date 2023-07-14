class Solution {
private:
    bool dfs(int node, vector<bool> &visited, vector<bool> &curVisited, vector<int> adj[]) {
        visited[node]=true;
        curVisited[node]=true;
        
        for(auto it:adj[node]) {
            if(!visited[it]) {
                if(dfs(it, visited, curVisited, adj)) {
                    return true;
                }
            }
            else if(visited[it] && curVisited[it]){
                return true;
            }
        }
        curVisited[node]=false;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        //make adjacency list
        vector<int> adj[n];
        for(auto it:prerequisites) {
            vector<int> data=it;
            int a=data[0];
            int b=data[1];
            adj[a].push_back(b);
        }
        
        vector<bool> visited(n, false), currVisited(n, false);
        
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                //find cycle present or not
                if(dfs(i, visited, currVisited, adj)) {
                    return false;
                }
            }
        }
        return true;
    }
};