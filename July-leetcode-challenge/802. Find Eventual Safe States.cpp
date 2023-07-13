class Solution {
private:
	bool dfs(int i, vector<bool> &visited, vector<bool> &dfsVisited, vector<bool> &present_cycle, vector<vector<int>>& graph) {
		visited[i]=true;
		dfsVisited[i]=true;

		vector<int> data=graph[i];
		for(auto it:data) {
			if(!visited[it]) {
				if(dfs(it, visited, dfsVisited, present_cycle, graph)) {
					return present_cycle[i] = true;
				}
			}
			else if(visited[it] && dfsVisited[it]) {
				return present_cycle[i] = true;
			}
		}
		dfsVisited[i]=false;
		return false;
	}
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> ans;
        vector<bool> present_cycle(n, false);
        vector<bool> visited(n, false), dfsVisited(n, false);

        for(int i=0; i<n; i++) {
        	if(!visited[i]) {
        		dfs(i, visited, dfsVisited, present_cycle, graph);
        	}
        }

        for(int i=0; i<n; i++) {
        	if(!present_cycle[i]) {
        		ans.push_back(i);
        	}
        }
        return ans;
    }
};