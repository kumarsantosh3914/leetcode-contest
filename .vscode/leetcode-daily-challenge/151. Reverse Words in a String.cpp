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
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int strt = 0, end = 0;
        int itrtr = 0;
        while (itrtr < n) {
            while (itrtr < n && s[itrtr] != ' ')
                s[end++] = s[itrtr++];

            if (strt < end) {
                reverse(s.begin() + strt, s.begin() + end); 
                if (end == n) break;
                s[end++] = ' ';
                strt = end;
            }
            itrtr++; 
        }
        if (end > 0 && s[end-1] == ' ')   s.resize(end-1);
        else  s.resize(end);
        return s;
    }
};