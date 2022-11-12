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
public:
    int getLength(int i){
        int ans = 0;
        while(i){
            i /= 10;
            ans++;
        }
        return ans;
    }
    
    int checkMaxSize(int limit, int fixed){
        if(limit<=5) return 0;
        int mul = 9;
        int ans = 0;
        int n = 1;
        int dec = 3 + n + fixed;
        while(limit - dec > 0 && n<=fixed){
            ans += mul*(limit - dec++);
            n++;
            mul *= 10;
        }
        return ans;
    }
    
    vector<string> splitMessage(string message, int limit) {
        int msize = message.size();
        int den = 1;
        int maxsize = checkMaxSize(limit, den);
        int maxm = maxsize;
        while(maxsize<msize && den<limit-4){
            maxsize = checkMaxSize(limit, ++den);
            maxm = max(maxsize, maxm);
        }
        
        if(maxm<msize) return {};
        
        vector<string> ans; int idx = 0;
        for(int i=1; i<=maxsize && idx<msize; i++){
            string temp;
            int cut = getLength(i) + 3 + den;
            int tlen = limit - cut;
            for(int j=0; j<tlen; j++){
                temp.push_back(message[idx++]);
            }
            temp.push_back('<');
            string numerator = to_string(i);
            for(char c : numerator) temp.push_back(c);
            temp.push_back('/');
            for(int k=0; k<den; k++) temp.push_back('#');
            temp.push_back('>');
            ans.push_back(temp);
        }

        string denominator = to_string(ans.size());
        for(string &str : ans){
            int i = 0;
            for(char &c : str){
                if(c=='#'){
                    c = denominator[i++];
                }
            }
        }
        return ans;
    }
};