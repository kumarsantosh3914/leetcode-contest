class Solution {
private:
    // Function to find the largest window size within the given string
    int largestWindow(string s, int k, char ch) {
        int low=0;
        int count=0;
        int maxi=1;
        for(int i=0; i<s.size(); i++) {
            // Increase the count if the current character is equal to the desired character
            if(s[i] == ch) count++;
            // Slide the window by increasing the low pointer until the count is within the allowed limit
            while(count > k) {
                // Decrease the count if the character at low pointer is equal to the desired character
                if(s[low] == ch) count--;
                low++;
            }
            // Update the maximum window size
            maxi=max(maxi, i-low+1);
        }
        return maxi;
    }
    
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        // Find the maximum window size for both 'F' and 'T' characters
        return max(largestWindow(answerKey, k, 'F'), largestWindow(answerKey, k, 'T'));
    }
};