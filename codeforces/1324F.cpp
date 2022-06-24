#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

const int N = 2e5;
int n, a[N], ans[N], dp[N];
vector<int> adj[N];

void dfs1(int u = 0, int p = -1){
    dp[u] = a[u];
    for(int v: adj[u]){
        if( v == p) continue;
        dfs1(v, u);
        dp[u] += max(dp[v], 0ll);
    }
}

void dfs2(int u = 0, int p = -1, int d = 0){
    ans[u] = dp[u] + d;
    for(int v: adj[u]){
        if(v == p) continue;
        dfs2(v, u, max(ans[u]-max(dp[v], 0ll), 0ll));
    }
}

int32_t main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(!a[i]) a[i] = -1;
    }
    for(int i = 1; i < n; i++){
        int u , v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1();
    dfs2();
    for(int i = 0; i < n; i ++){
        cout << ans[i] << " ";
    }
    return 0;
}
