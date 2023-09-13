class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n;  // Initialize total candy count to the number of children (each with at least 1 candy).
        int i = 1;      // Start from the second child (index 1).

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;  // If the current child has the same rating as the previous one, move to the next child.
                continue;
            }

            int peak = 0;  // Initialize the peak counter.

            // Calculate candy distribution for increasing slope (higher ratings).
            while (ratings[i] > ratings[i - 1]) {
                peak++;         // Increase the peak counter.
                candy += peak;  // Distribute candies according to the peak.
                i++;            // Move to the next child.
                if (i == n) return candy;  // If we reach the end of the ratings, return the total candy count.
            }

            // Handle decreasing slope (lower ratings).
            int dPeak = 0;  // Initialize the decreasing peak counter.
            while (i < n && ratings[i] < ratings[i - 1]) {
                dPeak++;        // Increase the decreasing peak counter.
                candy += dPeak; // Distribute candies according to the decreasing peak.
                i++;            // Move to the next child.
            }
            candy -= min(peak, dPeak);  // Subtract the minimum of peak and decreasing peak to avoid double-counting.
        }
        return candy;  // Return the total minimum number of candies required.
    }
};
