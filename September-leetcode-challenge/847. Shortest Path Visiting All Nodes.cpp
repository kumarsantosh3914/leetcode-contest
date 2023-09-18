class Solution {
    // Define a struct to represent the state of the BFS queue.
    struct State {
        int mask, node, dist;  // mask: Bitmask to track visited nodes, node: Current node, dist: Distance traveled.
    };

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(); // Get the number of nodes in the graph.
        int all_visited = (1 << n) - 1; // A bitmask representing all nodes visited.

        queue<State> q; // Initialize a queue for BFS.
        unordered_set<int> visited; // Use a set to store visited states.

        // Initialize the queue and visited set with starting states for each node.
        for (int i = 0; i < n; ++i) {
            q.push({1 << i, i, 0}); // Start from node 'i' with a bitmask representing only that node as visited, and distance 0.
            visited.insert((1 << i) * 16 + i); // Store the state as a hash value.
        }

        while (!q.empty()) {
            State cur = q.front(); q.pop(); // Dequeue the current state.

            if (cur.mask == all_visited) {
                return cur.dist; // If all nodes are visited, return the distance traveled.
            }

            // Iterate through neighbors of the current node.
            for (int neighbor : graph[cur.node]) {
                int new_mask = cur.mask | (1 << neighbor); // Update the bitmask by marking the neighbor as visited.
                int hash_value = new_mask * 16 + neighbor; // Calculate a unique hash value for the new state.

                if (visited.find(hash_value) == visited.end()) {
                    // If this state has not been visited before, add it to the visited set and enqueue it.
                    visited.insert(hash_value);
                    q.push({new_mask, neighbor, cur.dist + 1}); // Increment the distance by 1.
                }
            }
        }
        return -1; 
    }
};
