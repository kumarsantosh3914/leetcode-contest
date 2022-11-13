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
class Solution {
private:
    ll lcm(int a, int b) {
    return (a / __gcd(a, b)) * b;
   }
public:
    unsigned int ans = 0;
    int subarrayLCM(vector<int>& nums, int k) {
        unsigned int n = nums.size();
        for(int i=0; i<n; i++) {
            unsigned int curr_lcm = nums[i];
            for(int j=i; j<n; j++) {
                 curr_lcm = std::lcm(curr_lcm,nums[j]);
                 if(curr_lcm == k) ans++;
             }
         }
        return int(ans);
    }
};
