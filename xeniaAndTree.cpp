#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<climits>
using namespace std;
const int N = 1e5+1;
const int H = 19;
int par[N][H+1], lvl[N], parentCentroid[N], closestRed[N], subTree[N];
set<int> g[N];
int n, q, total_nodes = 0;
void dfs1(int z, int p){
    lvl[z] = lvl[p]+1;
    par[z][0] = p;
    for(int i = 1; i <= H; i++){
        par[z][i] = par[par[z][i-1]][i-1];
    }
    for(auto to: g[z]){
        if(to != p) dfs1(to, z);
    }
}
int lca(int x, int y){
    if(lvl[x] < lvl[y]) swap(x, y);
    for(int i = H; i >= 0; i--){
        if(lvl[x] - (1 << i) >= lvl[y]){
            x = par[x][i];
        }
    }
    if(x == y) return x;
    for(int i = H; i >= 0; i--){
        if(par[x][i] != par[y][i]){
            x = par[x][i];
            y = par[y][i];
        }
    }
    return par[x][0];
}
int distance(int u, int v){
    int d = lca(u, v);
    return lvl[u]+lvl[v]-2*lvl[d];
}
void dfs(int k, int p){
    total_nodes++;
    subTree[k] = 1;
    for(auto it: g[k]){
        if(it != p){
            dfs(it, k);
            subTree[k] += subTree[it];
        }
    }
}
int centroid(int k, int p){
    for(auto it: g[k]){
        if(it == p) continue;
        if(subTree[it] > (total_nodes >> 1)){
            return centroid(it, k);
        }
    }
    return k;
}
void decompose(int k, int p){
    total_nodes = 0;
    dfs(k, k);
    int node = centroid(k, k);
    parentCentroid[node] = p;
    for(auto it: g[node]){
        g[it].erase(node);
        decompose(it, node);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    int u, v;
    for(int i = 1; i < n; i++){
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    dfs1(1, 0);
    decompose(1, 0);
    closestRed[1] = 0;
    for(int i = 2; i <= n; i++){
        closestRed[i] = distance(i, 1);
    }
    for(int i = 1; i <= q; i++){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            int curr = x;
            while(curr != 0){
                closestRed[curr] = min(closestRed[curr], distance(x, curr));
                curr = parentCentroid[curr];
            }
        }
        else{
            int curr = x;
            int ans = INT_MAX;
            while(curr != 0){
                ans = min(ans, closestRed[curr] + distance(x, curr));
                curr = parentCentroid[curr];
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
