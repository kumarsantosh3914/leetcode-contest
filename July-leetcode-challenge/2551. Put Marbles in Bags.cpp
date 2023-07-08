class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k == 1 || weights.size() == k) return 0; // If k is 1 or the size of weights is k, return 0
        
        vector<int> candidates;
        for(int i=0; i<weights.size() - 1; i++) {
            candidates.push_back(weights[i] + weights[i + 1]); // Calculate the sum of consecutive weights and store them in candidates vector
        }

        sort(candidates.begin(), candidates.end()); // Sort the candidates vector in ascending order
        long long mini = 0, maxi = 0;
        for(int i=0; i<k - 1; i++) {
            mini += candidates[i]; // Calculate the sum of the lowest k-1 elements
            maxi += candidates[weights.size() - 2 - i]; // Calculate the sum of the highest k-1 elements
        }
        return maxi - mini; // Return the difference between the sum of highest k-1 elements and the sum of lowest k-1 elements
    }
};