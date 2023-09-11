#define mod 1000000007 

class Solution {
public:
    int countOrders(int n) {
        // if(n == 1) return 1;  // Base case: If n is 1, there is only one possible order.

        long long ans = 1;  

        for(int i=2; i<=n; i++) {  // Iterate from 2 to n (inclusive) to calculate the result for each value of n.
            int spaceNum = (i - 1) * 2 + 1;  // Calculate the number of spaces for this step.

            // Calculate the number of possible orders for the current step and multiply it with the accumulated result.
            // The formula used is: (spaceNum * (spaceNum + 1)) / 2
            // This is essentially calculating the number of ways to arrange items in a sequence with spaces in between.
            ans *= spaceNum * (spaceNum + 1) / 2;

            ans %= mod;  // Take the modulo operation to prevent overflow.
        }

        return (int)ans;  
    }
};
