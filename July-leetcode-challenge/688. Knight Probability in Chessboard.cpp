class Solution {
public:
    double memo[26][26][101]; // Memoization table to store intermediate results
    
    double knightProbability(int n, int k, int row, int column) {
        // Base cases
        if (row < 0 || column < 0 || row >= n || column >= n) {
            return 0;
        }
        if (k == 0) return 1.0; // If k (number of steps) is 0, the probability of staying on the board is 1.0
        
        // Check if the result is already memoized
        if (memo[row][column][k] > 0) {
            return memo[row][column][k];
        }
        
        double sum = 0.0; // Initialize sum to find the cumulative probability
        
        // Recursive calls to explore all possible moves from the current position
        sum += knightProbability(n, k - 1, row - 2, column - 1);
        sum += knightProbability(n, k - 1, row - 1, column - 2);
        sum += knightProbability(n, k - 1, row + 2, column + 1);
        sum += knightProbability(n, k - 1, row + 1, column + 2);
        sum += knightProbability(n, k - 1, row - 2, column + 1);
        sum += knightProbability(n, k - 1, row + 2, column - 1);
        sum += knightProbability(n, k - 1, row - 1, column + 2);
        sum += knightProbability(n, k - 1, row + 1, column - 2);
        
        sum /= 8.0; // Divide the sum by 8 since there are 8 possible moves a knight can make
        
        // Memoize the result for the current position and number of steps
        memo[row][column][k] = sum;
        
        return sum;
    }
};
