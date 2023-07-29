class Solution {
private:
    unordered_map<int, unordered_map<int, double>> store;
public:
    double soupServings(int N) {
        if (N >= 5000)
            return 1.0;
        else
            return helper(N, N);
    }
    double helper(int A, int B) {
	// Full probablity when A becomes empty first
        if (A == 0 && B != 0)
            return 1;
	// Half probablity when A and B become empty at the same time
        else if (A == 0 && B == 0)
            return 0.5;
	// Zero probablity when B becomes empty first
        else if (A != 0 && B == 0)
            return 0;
						
	// If the code reaches here, it implies that neither A nor B is empty yet. 
	// If there exist previous calculated result, return it.
        if (store[A][B] != 0)
            return store[A][B];
			
	// Otherwise, recursive for 4 possible selections
        double prob = 0;
        prob += 0.25 * helper(A - min(A, 100), B);
        prob += 0.25 * helper(A - min(A, 75), B - min(B, 25));
        prob += 0.25 * helper(A - min(A, 50), B - min(B, 50));
        prob += 0.25 * helper(A - min(A, 25), B - min(B, 75));
				
	// Store the calculated result
        store[A][B] = prob;
        return prob;
    }
};