class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0; // pointer for the left end of the subarray
        int ans = 0; // variable to store the length of the longest subarray
        int zeros = 0; // count of zeros in the subarray
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                zeros++; // increment the count of zeros
            }
            
            while (zeros >= 2) {
                if (nums[left] == 0) {
                    zeros--; // decrement the count of zeros
                }
                left++; // move the left pointer to exclude the leftmost zero
            }
            
            ans = max(ans, right - left); // update the length of the longest subarray
        }
        
        return ans;
    }
};