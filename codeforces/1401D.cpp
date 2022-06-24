#include<iostream>
#include<algorithm>

using namespace std;

#define int long long
const int MOD = 1e9+7;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int> > g(n);
        for(int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<bool> vis(n, false);
        vector<int> sz(n, 1);
        vector<int> edges;
        function<void(int)> dfs = [&](int v){
            vis[v] = true;
            for(auto k: g[v]){
                if(!vis[k]){
                    dfs(k);
                    sz[v] += sz[k];
                    edges.push_back(sz[k]*(n-sz[k]));
                }
            }
        };
        dfs(0);
        int m;
        cin >> m;
        vector<int> p(m);
        for(int i = 0; i < m; i++){
            cin >> p[i];
        }
        while(p.size() < n-1) p.push_back(1);
        sort(p.begin(), p.end());
        while(p.size() > n-1){
            int k = p.back();
            p.pop_back();
            (p.back() *= k) %= MOD;
        }
        sort(edges.begin(), edges.end());
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            (ans += edges[i]%MOD * p[i]) %= MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}
