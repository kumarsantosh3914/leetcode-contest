# Day 24 Leetcode Daily Challenge

# [Snakes and Ladders](https://leetcode.com/problems/snakes-and-ladders/description/)

## Graph - BFS
## Intuition
The intuition behind this code is that it uses a breadth-first search (BFS) algorithm to find minimum number of moves required to reach the last call of the board from the first cell. BFS is an algorithm that explores all the vertices of a graph or all the nodes of a tree level by level.
## Approach
The method starts by creating a vector of pair called `cells` that stores the row and column of each cell in the board. It also creates a vector of integers called `dist` that stores the minimum number of moves required to reach each cell and initializes it to -1.

It then uses a queue to keep track of the cells to be visited and starts by pushing the first cell (cell 1) into the queue. The method then enters a while loop that continues until the queue is empty. In each iteration of the loop, it takes the front element o fthe queue, which is the current cell, and pops it from the queue.

For the current cell, the method loops all the possible next cells which are from curr + 1 to min(curr + 6, n * n) (because in each move we can move to a dice roll max 6 steps) assigned yet. If it has not been assigned yet, the method assigns the minimum number of moves required to reach that cell as the minimum number of moves required to reach the current cell plus one. It also pushes the next cell into the queue to be visited in the next iteration.

The method then continues this process untill all the cells have been visited, and the minimum number of moves required to reach each cell has been assigned. Finally, the method returns the minimum number of moves required to reach the last cell, which is stored in dist[n * n].

It also handles the case if there is a snake or ladder at the cell, it directly assigns the destination cell number as the cell number.

## **Complexity**
## . Time complexity:
    The tiem complexity of this code is O(n^2), where n is the size of the board. This because the method uses a breadth-first search algorithm to traverse through each cell of the board and assigns the distance of each cell from the starting cell. The outer loop iterates n times, and the inner loop iterates n tiems, so the total number of iterations is n * n.
    Note that this is assuming the queue and vector operations have a constant time complexity, which is typical but not guaranteed.

## . Space complexity:
    The space complexity of this code is also O(n^2). This is because the method uses a vector of integers called "dist" to keep track of the minimum number of moves required to reach each cell, and this vector has nn elements. The method also uses a vector of pairs called "cells" to keep track of the row and column of each cell, and this vector also has nn elements. The method also uses a queue to keep track of the cells to be visited, which can have at most n*n elements.

## **Code**
```
class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size(), lbl = 1;
        vector<pair<int, int>> cells(n*n+1);
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[lbl++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dist(n*n+1, -1);
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next = curr + 1; next <= min(curr+6, n*n); next++) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        return dist[n*n];
    }
};
```




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

# Day 26 Leetcode Daily Challenge

# [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/description/)

## **Graph**
## **Intuition of this Problem**
We can solve this problem using various ways:
- **Dijkstra Algorithm** - Time Complexity - O(V^2)
- **Floyd Warshall Algorithm** - Time Complexity - O(V^3)
- **Bellman Ford Algorithm** - Time Complexity - O(V^3);

I used `simple BFS` to solve the problem. For further optimization in this solution we can use priority queue. But In this solution I didn't use.

## **NOTE: PLEASE READ APPROACH FIRST THEN SEE THE CODE. YOU WILL DEFINITELY UNDERSTAND THE CODE LINE BY LINE AFTER SEEING THE APPROACH.**


## **Approach for this Problem**
1. Initialize an adjacency list with the given flights information, where each index i represents the node i, and the corresponding value is a list of pairs (neighbor, price) representing the edges from node i to its neighboring nodes and the price of the flight.
2. Initialize a queue with the source node and its cost(0) and vector minCost with same size as the number of nodes, where each index i represents the minimum cost to reach node i and the corresponding value is initialized to INT_MAX.
3. Create a variable stops and initialize it to 0.
4. Start a while loop until the queue is not empty and stops are less than or equal to k (maximum stops allowed).
5. In the while loop, create a variable size equal to the size of the queue.
6. Start another while loop with the size of the queue.
7. In the inner while loop, pop the front element from the queue and assign it to a variable (curNode, cost).
8. Iterate through the neighbors and price of the current node from the adjacency list.
9. If the total cost to reach the neighbor is greater than or equal to the minimum cost to reach the neighbor, continue to the next iteration.
10. Else, update the mimimum cost to reach the neighbor as the total cost and push the neighbor and its cost to the queue.
11. End the inner while loop and increment the stop by 1.
12. End the outer while loop.
13. If the minimum cost to reach the destination is still INT_MAX, return -1, otherwise return the minimum cost to reach the destination.

## **Time Complexity and Space Complexity**
- Time complexity: O(V + E * K)
- Space complexity: O(V + E)

## **Code**
```
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto flight : flights){
            // flight[0] represent node i, flight[1] represent neighbor node of node i, flight[2] represent cost between node i to neighbor node
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        //it will store [node, cost]
        queue<pair<int, int>> q;
        q.push({src, 0});
        //it will store minimum cost to reach each node
        vector<int> minCost(n, INT_MAX);
        int stops = 0;
        while(!q.empty() && stops <= k){
            int size = q.size();
            while (size--) {
                auto [currNode, cost] = q.front();
                q.pop();
                for (auto& [neighbour, price] : adj[currNode]) {
                    if (price + cost < minCost[neighbour]){
                        minCost[neighbour] = price + cost;
                        q.push({neighbour, minCost[neighbour]});
                    }
                }
            }
            stops++;
        }
        if(minCost[dst] == INT_MAX)
            return -1;
        return minCost[dst];
    }
};
```

# Day 27 Leetcode Daily Challenge

# [Concatenated Words](https://leetcode.com/problems/concatenated-words/description/)

## **Intuition**
The intuition behind this this solution is to use dynamic programming to check if a word can be constructed by the concatenation of other words in the set.

## **Approach**
First,  the input list of words is converted into an unordered_set, which is an efficient data structure for checking if a word is in the set in constant time. Then, an empty vector res is created to store the concatenated words that are found.

The code then iterates over the input list of words. For each word, it creates a vector dp of size n + 1 where n is the length of the word. This vector is used to store whether it is possible to construct the word until a certain index by concatenating other words in the set. The vector is initially set to 0 for all indices, except for the first element, which is set to 1.

The code then iterates over the word again, and for each index i, it checks if the dp value at index i is 1, which means it is possible to construct the word until this index by concatenating other words. If so, it checks if there is a word in the set that starts from this index and has a length j - i, where j is the next index. If such a word is found, it updates the dp value at index j to 1.

Finally, after iterating over the word, the code checks if the dp value at the last index is 1, which means that the word can be constructed by the concatenation of other words in the set. If so, it adds the word to the result vector.

After iterating over all the words, the code returns the result vector, which contains all the concatenated words in the input list of words.

📍 Here is an example of how the code would work for the word "catdog" and the set of  words {"cat", "dog"};

1. First, the input list of  words is converted into an unordered_set, which is an efficient data structure for checking if a word is in the set in constant time.
2. Then, an empty vector res is created to store the concatenated words that are found.
3. The code then iterates over the input list of words. For each word "catdog", it creates a vector dp of size n + 1 where n is the length of the word. This vector is used to store whether it is possible to construct the word until a certain index by concatenating other words in the set. The vector is initially set to 0 for all indices, except for the first element, which is set to 1.
```
dp = [1, 0, 0, 0, 0, 0, 0]
```
4. The code then iterates over the word again, and for each index i, it checks if the dp value at index i is 1, which means it is possible to construct the word until this index by concatenating other words. If so, it checks if there is a word  in the set that starts from this index and has a length j - i, where j is the next index. If such a word is found, it updates the dp value at index j to 1.
```
i = 0, j = 3, check if "cat" is in set: Yes, update dp[3] = 1
i = 3, j = 6, check if "dog" is in set: Yes, update dp[6] = 1
```
5. Finally, after iterating over the word, the code checks if the dp value at the last index is 1, which means that the word can be constructed by the concatenation of the other words in the set. If so, it adds the word to the result vector.
```
dp = [1, 0, 0, 1, 0, 0, 1]
```
As the dp array's last index is 1, which means the word "catdog" can be constructed by the concatenation of other words in th set, so it's added to the result vector.

In this way, this approach is checking if a word is a concatenated word by breaking it down into substring and checking if each substring is a word in the set, making use of a dp array to store intermediate results. This method is much more efficient than checking all possible concatenation of words.

## **Time complexity:**
- **Time complexity:**

The time complexity of this solution is O(n * L^2), where n is the number of words in the input list and L is the maximum length of the words.
The main source of the time complexity is the nested loops that iterate over the words and the characters of the words. The outer loop iterates over the words and has a time complexity of O(n). The inner loop iterates over the characters of the words and has a time complexity of O(L). The inner loop also performs additional operations, such as checking if a word is in the set and updating the dp array, which also contribute to the overall time complexity.


## **Space complexity:**
- **Space complexity:**

The space complexity is O(n * L), where n is the number of words in the input list and L is the maximum length of the words. The main source of the space complexity is the dp array, which is created for each word and has a size of L. Additionally, creating a unordered_set of all the words also takes O(n) space.


## **Code**
```
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> words_set;
        for (string word : words) words_set.insert(word);
        vector<string> res;
    
        for (string word : words) {
            int n = word.size();
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if (!dp[i]) continue;
                for (int j = i + 1; j <= n; j++) {
                    if (j - i < n && words_set.count(word.substr(i, j - i))) {
                        dp[j] = 1;
                    }
                }
                if (dp[n]) {
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};
```

# Day 28 Leetcode Daily Challenges

# [Data Stream as Disjoint Intervals](https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/)

### **For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ...., then the summary will be:**

```
[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
```
**A simple method is put integers to a set, then iterate data in set to construct the interval list.**

### **Time complexity:**
**addNum is O(logN), getIntervals is O(n).**

**Space complexity:** O(n)

## **Code**
```
class SummaryRanges {
public:
 
  SummaryRanges() {
        
  }
    
  void addNum(int val) {
    data_given.insert(val);
  }
    
  vector<vector<int>> getIntervals() {
      vector<vector<int>> res;
      int start = -1;
      int end = -1;
      for ( auto  &item: data_given) {
          if (start == -1) {
              start = item;
              end = item;
          } else if (item == end + 1) {
              end = item;
          } else {
              res.push_back({start, end});
              start = end = item;
          }
      }
      
      if (start != -1) res.push_back({start, end});
      
      return res;
  }
private:
  set<int> data_given;
};
```

# Day 29 Leetcode Daily Challenges

# [LFU Cache](https://leetcode.com/problems/lfu-cache/description/)

## **Intuition of this Problem:**
for, get(key)-->
gets the value of the key if exists, eles -1;

for, put(key, value)-->
Condition 1: Updates the value of the key if present, else inserts the key directly. 
Condition 2: When cache is full-->
case 1: if cache if full, removes the LFU guy
case 2: if cache is full, but exists multiple LFU guys (or a tie exists), then remove the LRU one and then add new node.

## *NOTE: PLEASE READ APPROACH FIRST THEN SEE THE CODE. YOU WILL DEFINITELY UNDERSTAND THE CODE LINE BY LINE AFTER SEEING THE APPROACH.*

## **Approach for this Problem:**
1. The class LFU Cache has three unordered_map data strucutures: 

   - KeyValue: stores the key-value pairs, with the key as the first element of the pair and the value as the second element.
   - FreqList: stores the keys in a list, with the key's frequency as the index of the list.
   - Pos: stores the position of each key in the FreqList.
2. The class also has a private integer variable 'capacity' that is initialized in the constructor and represents the maximum number of key-value pairs that can be store in the cache.
3. The get() function is used to retrieve a value from the cache given a key. If the key is not found in the keyValue map, -1 is returned. Otherwise, the following steps are taken:
   - The key's current frequency is retrieved from keyVal.
The key is removed from the list at index equal to its current frequency in the freqList map.
   - The key's frequency in keyVal is incremented by 1.
   - The key is added to the list at index equal to its new frequency in the freqList map.
   - The key's position in the freqList map is updated in the pos map.
   - If the list at index equal to the current minimum frequency is empty, the minimum frequency is incremented by 1.
   - The value associated with the key is returned.

4. The put() function is used to add a new key-value pair to the cache or update the value of an existing key.

   - If the capacity is 0, the function returns immediately. 
   - If the key already exists in the keyValue map, the following steps are taken:
   
      - The key's value is updated in the keyVal map.
      - The key is removed from the list at index equal to its current frequency in the freqList map.
      - The key's frequency in keyVal is incremented by 1.
      - The key is added to the list at index equal to its new frequency in the freqList map.
      - The key's position in the freqList map is updated in the pos map.
      - If the list at index equal to the current minimum frequency is empty, the minimum frequency is incremented by 1.
   - If the key does not already exist in the keyVal map and the size of keyValue is equal to the capacity, the following steps are taken:

     - The key at the front of the list at index equal to the current minimum frequency in the freqList map is removed from all three maps (keyValue, FreqList, pos).

   - A new key-value pair is added to keyValue, with a frequency of 1.
   - The key is added to the list at index 1 in the freqList map. The key's position in the freqList map is updated in the pos map.
   - The minimum frequency is set to 1.

## **Time Complexity and Space Complexity**
- Time complexity:

  - get(): O(1)
  - put(): O(1)

- Space complexity: O(n) //where n is the capacity of the cache.

In this implementation, we are going three unordered_maps to store the key-value pairs, the frequency lists, and the position of the keys in the frequency lists. This allows us to quickly access, update and remove elements in O(1) time complexity. The get() and put() operations both have O(1) time complexity.

## **_Code_**
```
class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int,pair<int,int>> keyVal;
    unordered_map<int,list<int>> freqList;
    unordered_map<int,list<int>::iterator> pos;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyVal.find(key) == keyVal.end())
            return -1;
        freqList[keyVal[key].second].erase(pos[key]);
        keyVal[key].second++;
        freqList[keyVal[key].second].push_back(key);
        pos[key] = --freqList[keyVal[key].second].end();
        if(freqList[minFreq].empty())
            minFreq++;
        return keyVal[key].first;
    }
    
    void put(int key, int value) {
        if(!capacity)
            return;
        if(keyVal.find(key) != keyVal.end()) {
            keyVal[key].first = value;
            freqList[keyVal[key].second].erase(pos[key]);
            keyVal[key].second++;
            freqList[keyVal[key].second].push_back(key);
            pos[key] = --freqList[keyVal[key].second].end();
            if(freqList[minFreq].empty())
                minFreq++;
            return;
        }
        if(keyVal.size() == capacity) {
            int delKey = freqList[minFreq].front();
            keyVal.erase(delKey);
            pos.erase(delKey);
            freqList[minFreq].pop_front();
        }
        keyVal[key] = {value,1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
