class Solution {
private:
    int ans=0;
    void helper(int i, vector<vector<int>> &vec, int l, vector<int> &temp) {
        if(i==vec.size()) {
            for(auto a:temp) if(a != 0) return ;
                ans=max(ans,l);
                return ;
        }
        helper(i+1,vec,l,temp);
        temp[vec[i][0]]--;
        temp[vec[i][1]]++;
        helper(i+1,vec,l+1,temp);
        temp[vec[i][0]]++;
        temp[vec[i][1]]--;
        
    }
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> temp(n,0);
        helper(0,requests,0,temp);
        return ans;
    }
};