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
// #define l "\n"
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define vv vector<vector<int> > 
#define um unordered_map<int, int>
#define m map<int,int>

class Solution {
    int guessNumber(int n) {
        int start = 1;
        int end = n;
        while(start <= end) {
            int mid = start + (end - start)/2;
            int value = guess(mid);
            if(value == 0) return mid;
            if(value == -1) end = mid - 1;
            else start = mid + 1;
        }
        return -1;
    }
};