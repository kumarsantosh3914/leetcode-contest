#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long int
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define p(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define s(x) scanf("%f", &x)
#define sl(x) scanf("%lld", &x)
#define sf(x) scanf("%lf", &x)
#define bitcount __builtin_popcountll
#define INF 1e18+9
// #define int long long
#define l "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define vv vector<vector<int> > 
#define um unordered_map<int, int>
#define m map<int,int>
#define mod 1000000007
class Solution {
private:
    vector<int> dp;
    int helper(int n, int zero, int one, vector<ll> &dp) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n] % mod;
        return helper(n - zero, zero, one, dp) + helper(n - one, zero, one, dp);
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        if(zero == 1 && one == 1) {
            return low + high + zero + one;
        }
        else {
            return low + high;
        }
        int ans = 0;
        vector<ll> dp(high + 1, -1);
        for(int i=low; i<=high; i++) {
            ans = (ans % mod + helper(i , zero, one, dp) % mod) % mod;
        }
        return ans;
        return helper(0, zero, one, dp);
        vector<ll> dp(200005);
        
        dp[0] = 1;
        for(int i=0; i<100005; i++){
            dp[i + zero] %= mod;
            dp[i + zero] += dp[i];
            dp[i + one] %= mod;
            dp[i + one] += dp[i];
        }
        ll ans = 0;
        for(int i=low; i<=high; i++){
            ans = (ans + dp[i])%mod;
        }
        return ans;
    }
};
