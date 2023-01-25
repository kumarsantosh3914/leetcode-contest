# Day 25 Leetcode Daily Challenge

# [Find Closest Node to Given Two Nodes](https://leetcode.com/problems/find-closest-node-to-given-two-nodes/description/)

## Graph - DFS
## Intuition
![alt text](./assets/graphs.jpeg)

## Approach
1. Initialize variables n to the size of the edges array, ans to -1, and minDist to the maximum value(INT_MIN) of an int.
2. Create two arrays distance1 and distance2 of size n and initialize all elements to 0. Also, create two arrays visited1 and visited2 of size n and initialize all elements to false.
3. Run the depth-first-search(DFS) algorithm from node1 and update the distance1 and visited1 arrays accordingly.
4. Run the DFS algorithm from node2 and update the distance2 and visited2 array accordingly. 
5. Iterate through all nodes curNode in the graph.
6. For each node, check if it has been visited by both DFS calls, and if its maximum distance from node1 and node2 i.e (max(distance1[curNode], distance2[curNode])) is less than the current value of minDist.
7. If the above conditions are met, update the value of minDist and ans to the current node's distance and index, respectively.
8. Return ans as the result.
9. This algorithm finds the closest meeting point between two given nodes in a graph by using DFS to calculate the distance from each node to all other nodes in the graph. It only considers nodes that are reachable from both given nodes, and chooses the one that has the smallest maximum distance from the two given nodes.

## Code 
```class Solution {
    private:
        void dfs(int node, vector<int> &edges, vector<int> &distance, vector<bool> &visited) {
            visited[node] = true;
            int neighbor = edges[node];
            if(neighbor != -1 && visited[neighbor] == false) {
                distance[neighbor] = distance[node] + 1;
                dfs(neighbor, edges, distance, visited);
            } 
        }
    public:
        int closestMeetingNode(vector<int>& edges, int node1, int node2) {
            int n = edges.size();
            int ans = -1;
            int minDist = INT_MAX;
            /**
             * distance1 store the distance from node1 to all the neighbour nodes and 
             * distance2 store the distance form node2 to all the neighbour nodes
             */
            vector<int> distance1(n, 0), distance2(n, 0);
            /**
             * visited array helps us to identify wheather we visited to particular node from node1
             * or not similarly for visited2
             */
            vector<bool> visited1(n, false), visited2(n, false);
            // calling dfs from both the nodes i.e node1 and node2
            dfs(node1, edges, distance1, visited1);
            dfs(node2, edges, distance2, visited2);

            for(int curNode=0; curNode<n; curNode++) {
                if(visited1[curNode] == true && visited2[curNode] == true && minDist > max(distance1[curNode], distance2[curNode])) {
                    minDist = max(distance1[curNode], distance2[curNode]);
                    ans = curNode;
                }
            }
            return ans;
        }
    };

```
