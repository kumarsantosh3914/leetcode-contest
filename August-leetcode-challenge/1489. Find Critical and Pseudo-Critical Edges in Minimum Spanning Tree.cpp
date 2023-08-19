// UnionFind class to implement the Union-Find (Disjoint Set Union) data structure
class UnionFind {
private:
    vector<int> find, rank;
public:
    UnionFind(int n) {
        rank = vector<int>(n, 1);
        find.resize(n);
        for (int i = 0; i < n; i++) find[i] = i; // Initialize each element as its own parent
    }

    int Find(int x) {
        if (x == find[x]) return x; // If the element is its own parent, return it
        else return find[x] = Find(find[x]); // Path compression by assigning parent directly
    }

    void Union(int x, int y) {
        int findX = Find(x), findY = Find(y);
        if (findX == findY) return; // If x and y are already in the same set, no need to union

        // Union by rank to optimize the tree height
        if (rank[findX] > rank[findY]) swap(findX, findY);
        find[findX] = findY; // Make the parent of x the parent of y
        if (rank[findX] == rank[findY]) rank[findY]++; // Increase rank if both sets have the same rank
    }
};

class Solution {
private:
    // Calculate the weight of the Minimum Spanning Tree (MST) while blocking a specific edge
    int getMST(int n, vector<vector<int>> &edges, int blockedge, int preEdge = -1) {
        UnionFind uf(n);
        int weight = 0;

        // Include the preEdge in the MST if provided
        if (preEdge != -1) {
            weight += edges[preEdge][2];
            uf.Union(edges[preEdge][0], edges[preEdge][1]);
        }

        // Build the MST while excluding the blockedge
        for (int i = 0; i < edges.size(); i++) {
            if (i == blockedge) continue;
            const auto &edge = edges[i];
            if (uf.Find(edge[0]) == uf.Find(edge[1])) continue; // Skip if they are already connected
            uf.Union(edge[0], edge[1]); // Union the two components
            weight += edge[2]; // Add the weight of the current edge to the MST
        }

        // Check if all nodes are in the same component (connected)
        for (int i = 0; i < n; i++) {
            if (uf.Find(i) != uf.Find(0)) return 1e9 + 7; // Return a large value if not connected
        }
        return weight; // Return the weight of the MST
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // Append the edge index to each edge to track them during sorting
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        // Sort the edges in increasing order of weights
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });

        // Calculate the weight of the original MST without blocking any edges
        int originMST = getMST(n, edges, -1);

        vector<int> critical, nonCritical;

        // Iterate through each edge and classify them as critical or non-critical
        for (int i = 0; i < edges.size(); i++) {
            if (originMST < getMST(n, edges, i)) {
                critical.push_back(edges[i][3]); // Mark as critical if adding it increases MST weight
            } else if (originMST == getMST(n, edges, -1, i)) {
                nonCritical.push_back(edges[i][3]); // Mark as non-critical if adding it maintains MST weight
            }
        }
        return {critical, nonCritical}; 
    }
};
