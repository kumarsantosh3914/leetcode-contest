class Solution {
private:
    // Depth-First Search (DFS) function to find the itinerary
    // Parameters:
    // - fromAirport: The current airport we are exploring
    // - path: The current path of airports visited
    // - ans: The final itinerary to be constructed
    // - numberOfTickets: The total number of tickets
    // - adj: An adjacency map representing the flights between airports
    bool dfs(string fromAirport, vector<string> &path, vector<string> &ans, 
             int numberOfTickets, unordered_map<string, vector<string>> &adj) {
        
        // Add the current airport to the path
        path.push_back(fromAirport);

        // If the path size matches the number of tickets + 1, it means we have found a valid itinerary
        if (path.size() == numberOfTickets + 1) {
            ans = path; // Update the final itinerary
            return true; // Indicate that a valid itinerary has been found
        } 

        // Get the list of neighbors (destinations) for the current airport
        vector<string> &neighbors = adj[fromAirport];
        
        for (int i = 0; i < neighbors.size(); i++) {
            string toAirport = neighbors[i];

            // Remove the current neighbor from the list temporarily
            neighbors.erase(neighbors.begin() + i);

            // Recursively explore the neighbor
            if (dfs(toAirport, path, ans, numberOfTickets, adj) == true)
                return true; // If a valid itinerary is found, exit the loop

            // Restore the neighbor back to its original position in the list
            neighbors.insert(neighbors.begin() + i, toAirport);
        }

        // If no valid itinerary is found, backtrack by removing the current airport from the path
        path.pop_back();
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        vector<string> ans;
        int numberOfTickets = tickets.size();
        
        // Create an adjacency map to represent the flights between airports
        for (auto &it: tickets) {
            string u = it[0];
            string v = it[1];
            adj[u].push_back(v);
        }

        // Sort the destinations in lexical order for each airport
        for (auto &edges: adj) {
            sort(edges.second.begin(), edges.second.end());
        }

        vector<string> path; // Initialize the current path
        dfs("JFK", path, ans, numberOfTickets, adj); // Start DFS from the JFK airport
        return ans; 
    }
};
