class Solution {
private:
    void helper(int ind, vector<int> &cookies, vector<int> &vec, int k, int &ans) {
        //base case
        if(ind == cookies.size()) {
            int maxi = INT_MIN;
            for(int i=0; i<k; i++) {
                maxi = max(maxi, vec[i]);
            }
            ans = min(ans, maxi);
            return;
        }
        
        for(int i=0; i<k; i++) {
            vec[i] += cookies[ind];
            helper(ind + 1, cookies, vec, k, ans);
            vec[i] -= cookies[ind];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        int n = cookies.size();
        vector<int> vec(k, 0); // vector is store each sum of the k subsets
        helper(0, cookies, vec, k, ans);
        return ans;
    }
};
