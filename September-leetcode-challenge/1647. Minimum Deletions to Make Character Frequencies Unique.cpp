class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26);
        for(auto a:s) {
            v[a-'a']++;
        }
        sort(v.begin(),v.end(),greater<int>());
        int freq=v[0];
        int ans=0;
        for(auto a:v) {
            if(a>freq) {
                if(freq>0) ans+=(a-freq);
                else ans+=a;
            }
            freq=min(freq-1,a-1);
        }
        return ans;
    }
};