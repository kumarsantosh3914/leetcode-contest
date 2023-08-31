class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long totalReplacements = 0;
        // Start from the last element and work backwards
        int currentElement = nums[n - 1];
        
        for (int i = n - 1; i >= 0; i--) {
            // Calculate how many times the current element can be divided by the previous element
            int divisions = nums[i] / currentElement;
            // If there's a remainder after division, we need an additional division
            if ((nums[i] % currentElement) != 0) {
                divisions++;
                // Update the current element to reflect the division with the additional remainder
                currentElement = nums[i] / divisions;
            }
            // Count the number of replacements needed and add to the total
            totalReplacements += divisions - 1;
        }
        return totalReplacements;
    }
};
