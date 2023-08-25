class Solution {
public:
    // Recursive helper function to check if s3 is formed by interleaving s1 and s2
    bool helper(string& s1, string& s2, string& s3, int l1, int l2, int l3, vector<vector<int>>& dp) {
        // Base case: If all strings are empty, we've successfully formed s3
        if (l1 < 0 && l2 < 0 && l3 < 0) {
            return true;
        }
        
        // If the current state has already been calculated, return it
        if (l1 >= 0 && l2 >= 0 && dp[l1][l2] != -1) {
            return dp[l1][l2];
        }
        
        // If the current characters of s1 and s2 match the current character of s3
        if (l1 >= 0 && s1[l1] == s3[l3] && l2 >= 0 && s2[l2] == s3[l3]) {
            // Check if interleaving by excluding each string one by one
            return dp[l1][l2] = (helper(s1, s2, s3, l1 - 1, l2, l3 - 1, dp) || helper(s1, s2, s3, l1, l2 - 1, l3 - 1, dp));
        }
        // If only s1 matches the current character of s3
        else if (l1 >= 0 && s1[l1] == s3[l3]) {
            // Move to the previous character of s1 and s3
            return helper(s1, s2, s3, l1 - 1, l2, l3 - 1, dp);
        }
        // If only s2 matches the current character of s3
        else if (l2 >= 0 && s2[l2] == s3[l3]) {
            // Move to the previous character of s2 and s3
            return helper(s1, s2, s3, l1, l2 - 1, l3 - 1, dp);
        }
        // If none of the conditions match, we cannot form s3
        return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        // If the total length of s3 is not equal to the sum of lengths of s1 and s2, return false
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        // Call the helper function starting from the end of each string
        return helper(s1, s2, s3, s1.size() - 1, s2.size() - 1, s3.size() - 1, dp);
    }
};
