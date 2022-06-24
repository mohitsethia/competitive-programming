#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

#define int long long
using namespace std;


void dfs(int spl, int p, vector<int> g[], vector<int> &sz){
    if((int)g[spl].size() == 0ll) return;
    if((int)g[spl].size() == 1ll && g[spl][0] == p){
        sz[spl] = 0;
        return;
    }
    else{
        for(auto it: g[spl]){
            if(spl != p){
                dfs(it, spl, g, sz);
                sz[spl] += sz[it]+1;
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> g[n+1];
        // vector<int> sz(n+1);
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(g[x].size() <= 1){
            cout << "Ayush\n";
            continue;
        }
        else{
            if(n%2 == 0) cout << "Ayush\n";
            else cout << "Ashish\n";
        }
        // dfs(x, -1, g, sz);
        // for(auto it: g[x]){
            // sz[x] = min(sz[x], sz[it]);
        // }
        // if(sz[x]%2 == 0){
            // cout << "Ashish\n";
        // }
        // else{
            // cout << "Ayush\n";
        // }
    }
    return 0;
}
