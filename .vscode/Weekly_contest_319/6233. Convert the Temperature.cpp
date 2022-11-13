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
public:
    vector<double> convertTemperature(double C) {
        vector<double> ans;
        double K = (C + 273.15);
        ans.push_back(K);
        double F;
        F=C*9/5.0+32.0;
        
        ans.push_back(F);
        return ans;
        
    }
};