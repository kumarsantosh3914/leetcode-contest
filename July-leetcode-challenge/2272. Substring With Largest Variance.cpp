class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        // Initialize a frequency array to keep track of the count of each character
        vector<int> freq(26);
        for(auto& c:s){
            freq[c-'a']++;
        }
        // Iterate through all possible pairs of characters (ch1, ch2)
        for(char ch1='a'; ch1<='z'; ch1++){
            for(char ch2='a'; ch2<='z'; ch2++){
                // Skip the pair if ch1 is equal to ch2 or if either ch1 or ch2 don't appear in the string
                if(ch1==ch2 or !freq[ch1-'a'] or !freq[ch2-'a']){
                    continue;
                }
                // Try two rounds of iteration, one in original string order and one in reversed string order
                for(int rev=1;rev<=2;rev++){
                    int cnt1 = 0, cnt2 = 0;
                    for(auto& c:s){
                        // Count the occurrences of ch1 and ch2
                        cnt1 += c==ch1;
                        cnt2 += c==ch2;
                        // Reset the counts if cnt1 becomes less than cnt2
                        if(cnt1<cnt2){
                            cnt1 = cnt2 = 0;
                        }
                        // Update the answer by taking the maximum variance between cnt1 and cnt2
                        if(cnt1>0 and cnt2>0){
                            ans = max(ans,cnt1-cnt2);
                        }
                    } 
                    // Reverse the string for the second round of iteration
                    reverse(s.begin(),s.end());
                }
            }
        }
        return ans;
    }
};