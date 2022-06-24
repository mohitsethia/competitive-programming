#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
vector<pair<int, int> > graph[105];
vector<bool> vis;
bool dfs(int src, int dest, int color){
    vis[src] = true;
    if(src == dest) return true;
    for(int i = 0; i < (int)graph[src].size(); i++){
        pair<int, int> e = graph[src][i];
        if(e.second == color && !vis[e.first]){
            if(dfs(e.first, dest, color)) return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        --u, --v, --c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        --u, --v;
        int res = 0;
        for(int i = 0; i < 100; i++){
            vis = vector<bool>(105, false);
            if(dfs(u, v, i)) res++;
        }
        cout << res << endl;
    }
    return 0;
}
