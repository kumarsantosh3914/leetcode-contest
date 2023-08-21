class Solution {
private:
    // This function performs a topological sort on the given graph.
    vector<int> topoSort(vector<unordered_set<int>> &graph, vector<int> &indegree) {
        // Create a queue to store the nodes with indegree 0.
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Create an empty vector to store the result.
        vector<int> ans;
        // While the queue is not empty, do the following:
        while (!q.empty()) {
            // Remove the first node from the queue.
            int t = q.front();
            q.pop();

            // Add the node to the result vector.
            ans.push_back(t);

            // For each neighbor of the node, decrease its indegree by 1.
            for (auto next : graph[t]) {
                indegree[next]--;

                // If the neighbor's indegree becomes 0, add it to the queue.
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        for(int i = 0; i < indegree.size(); i++) {
            if(indegree[i] > 0) return {};
        }
        return ans;
    }

public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // Group the isolated item by itself.
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }

        // Build the graphs.
        vector<unordered_set<int>> graphGroup(m), graphItem(n);
        vector<int> inGroup(m), inItem(n);
        for (int i = 0; i < n; i++) {
            int toGroup = group[i];
            for (auto from : beforeItems[i]) {
                int fromGroup = group[from];

                // Add an edge from fromGroup to toGroup if they are not in the same group and there is no edge between them yet.
                if (fromGroup != toGroup && !graphGroup[fromGroup].count(toGroup)) {
                    graphGroup[fromGroup].insert(toGroup);
                    inGroup[toGroup]++;
                }

                // Add an edge from from to i if there is no edge between them yet.
                if (!graphItem[from].count(i)) {
                    graphItem[from].insert(i);
                    inItem[i]++;
                }
            }
        }

        // Perform topological sort on the graphs.
        vector<int> sortedGroup = topoSort(graphGroup, inGroup);
        vector<int> sortedItem = topoSort(graphItem, inItem);

        // If either of the sorted lists is empty, then there is no topological sort, so return an empty list.
        if (sortedGroup.empty() || sortedItem.empty()) {
            return {};
        }

        // Create a mapping from group id to the items in that group.
        vector<vector<int>> group2Item(m);
        for (auto item : sortedItem) {
            group2Item[group[item]].push_back(item);
        }

        // Create the final sorted list by merging the sorted lists of groups and items.
        vector<int> ans;
        for (int groupId : sortedGroup) {
            for (int item : group2Item[groupId]) {
                ans.push_back(item);
            }
        }
        return ans;
    }
};