class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> mp;
        for(int i=0; i<s.size(); i++) mp[s[i]]=i;
        
        vector<bool> vis(26, false);
        string ans="";
        for(int i=0; i<s.size(); i++) {
            if(vis[s[i] - 'a']) continue;
            
            while(!ans.empty() && ans.back() > s[i] && mp[ans.back()] > i) {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[s[i] - 'a'] = true;
        }
        return ans;
    }
};