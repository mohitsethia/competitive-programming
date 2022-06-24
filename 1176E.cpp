#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> adj[n];
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, -1);
        function<void(int)> dfs = [&](int u){
            vis[u] = 0;
            for(int v: adj[u]){
                if(~vis[v]){
                    continue;
                }
                dfs(v);
                if(!vis[v]) vis[u] = 1;
            }
        };
        dfs(0);
        int res = 0;
        for(int i = 0; i < n; i++){
            res += vis[i];
        }
        cout << res << "\n";
        for(int i = 0; i < n; i++){
            if(vis[i]) cout << i+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}
