#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
#include<set>
#include<queue>
#include<set>
#include<numeric>
#include<iomanip>
using namespace std;
using ll = long long;

#define pi pair<ll, ll>
#define mk make_pair
#define pb push_back
#define vi vector<ll>
#define vpi vector<pi>

const int N = 1010;


vector<ll> g[N];
vector<pair<ll,vector<ll>>> pt;

void dfs(ll st,ll e,ll vis[],vi rs,ll w){
   rs.push_back(st);
   if(st == e){
       pt.pb({w*(rs.size()-1),rs});
       return;
   }
   for(auto &u : g[st]){
       if(vis[u] == 0){
          vis[st] = 1;
          dfs(u,e,vis,rs,w);
          vis[st] = 0;
       }
   }
}

int main()
{
    ll n,m,t,c,u,v;
    cin >> n >> m >> t >> c;
    while(m--){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    if(n <= 2)
        cout << "-1\n";
    else{
        vi rs;
        ll w = c;
        ll vis[n+1];
        memset(vis, 0, sizeof(vis));
        dfs(1,n,vis,rs,w);
        if(pt.size() <= 1){
            cout << "-1\n";
        }
        else{
            sort(pt.begin(),pt.end());
            ll te = 0;
            ll nt = 0;
            for(ll i=1;i< (ll)pt[1].second.size();i++){
                te += c;
                if(i == pt[1].second.size()-1) break;
                ll temp = te/t;
                if(temp&1){
                    te = (temp+1)*t;
                }
                //te += c + (nt-te);
                //while(nt < te)
                  //  nt += t;
            }
            cout << te << endl;
        }
    }
    return 0;
}

