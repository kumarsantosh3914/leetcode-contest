class Solution {
public:
    int bestClosingTime(string customers) {
        // Initialize variables to keep track of the best closing time and the maximum score.
        int idx = -1, maxScore = 0;

        // Initialize a variable to track the current score.
        int score = 0;
        for (int i = 0; i < customers.size(); i++) {
            // If the customer at index 'i' arrived ('Y' indicates arrival),
            // increment the score; otherwise, decrement it ('N' indicates no arrival).
            if (customers[i] == 'Y') {
                score++;
            } else {
                score--;
            }
            // Check if the current score is greater than the maximum score seen so far.
            if (score > maxScore) {
                // If yes, update the maximum score and the corresponding index.
                maxScore = score;
                idx = i;
            }
        }
        // Return the index of the best closing time, adjusted by 1 since indices are 0-based.
        return idx + 1;
    }
};
