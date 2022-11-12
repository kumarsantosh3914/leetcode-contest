/*
Main Idea
Alice can travel to any leaf from 0 but there is only one path for Bob. So we will find the path Bob 
will follow and update the contribution of each node in the path first.
With the first dfs we will find the time to travel to each node 'u' from 0 and previous node of 'u' in the path.
Now we can follow the path from Bob's node to 0 using the previous node we found earlier. 
In each node 'u' we will check if Alice will reach it first or Bob will. If Bob reaches it faster than Alice, 
we will make amount[u] = 0 and if both of them reaches at the same time we make amount[u] =amount[u]/2.

Finally we will run our second dfs to find the cumulative sum of amount in the path to each leaf and return the maximum.
*/
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
    vector<vector<int>>adj;
    vector<int>par,dis;
	//Find the parent and distance from node 0
    void dfs(int u,int p = 0,int d = 0){
        dis[u] = d;
        par[u] = p;
        for(int v:adj[u]){
            if(v==p)continue;
            dfs(v,u,d+1);
        }
    }
	// Find total sum to each node
    int dfs2(int u,vector<int>&amount,int p= 0){
        int ret = amount[u];
        int mxc = -INT_MAX;
        for(int v:adj[u]){
            if(v!=p){
                mxc= max(mxc,dfs2(v,amount,u));
            }
        }
		//if the node is leaf we just return its amount
        if(mxc==-INT_MAX)return ret;
        else return ret+mxc;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        adj.resize(n,vector<int>());
        for(auto&e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        par.resize(n);
        dis.resize(n);
        dfs(0);
        int cur = bob;
        int bob_dis = 0;
		//update the path of from Bob to 0
        while(cur!=0){
            if(dis[cur]>bob_dis){
                amount[cur] = 0;
            }else if(dis[cur]==bob_dis){
                amount[cur]/=2;
            }
            cur = par[cur];
            bob_dis++;
        }
        return dfs2(0,amount);
    }
    
};