class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        // Create a graph representation using adjacency list
        vector<vector<pair<int, double>>> to(n);
        for (int i = 0; i < edges.size(); i++)
        {
            // Add each edge along with its probability to both vertices' adjacency list
            to[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
            to[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
        }

        // Array to store the maximum probability for each node
        vector<double> Prob(n, 0);

        // Queue for the breadth-first search
        queue<int> Q;

        // Add the starting node to the queue and set its probability to 1
        Q.push(start);
        Prob[start] = 1;

        while (!Q.empty())
        {
            // Get the next node from the queue
            int node = Q.front();
            Q.pop();

            // Traverse through each child node of the current node
            for (auto child : to[node])
            {
                int nxt = child.first;
                double p = child.second;

                // Update the probability of the child node if it is greater than the current probability
                if (Prob[nxt] < Prob[node] * p)
                {
                    Prob[nxt] = Prob[node] * p;
                    // Add the child node to the queue for further exploration
                    Q.push(nxt);
                }
            }
        }

        // Return the maximum probability of reaching the end node from the start node
        return Prob[end];
    }
};