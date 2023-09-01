class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // Create an array to store the effective range (start to end) for each point
        vector<int> startEnd(n + 1, 0);
        // Populate the startEnd array based on the given ranges
        for(int i = 0; i < ranges.size(); i++) {
            int left = max(0, i - ranges[i]);        // Leftmost point that can be reached from this point
            int right = min(n, i + ranges[i]);       // Rightmost point that can be reached from this point
            startEnd[left] = max(startEnd[left], right); // Store the effective range
        }

        int curEnd = 0, maxEnd = 0, taps = 0;
        // Traverse through the points and calculate the minimum taps required
        for(int i = 0; i < ranges.size(); i++) {
            if(i > maxEnd) {
                // If the current point cannot be reached, return -1
                return -1;
            }
            if(i > curEnd) {
                // If the current point is beyond the current reachable range, increase taps
                taps++;
                curEnd = maxEnd; // Update the current reachable range
            }
            // Update the maximum reachable end from the current point
            maxEnd = max(maxEnd, startEnd[i]);
        }
        return taps;
    }
};
