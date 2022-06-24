//binary lifting
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
const int N = 3e5+5;
const int H = 19;
vector<int> tree[N];
int par[N][H+1], lvl[N];
void dfs(int z, int p){
    lvl[z] = lvl[p]+1;
    par[z][0] = p;
    for(int i = 1; i <= H; i++){
        par[z][i] = par[par[z][i-1]][i-1];
    }
    for(auto x: tree[z]){
        if(x == p) continue;
        dfs(x, z);
    }
}
int lca(int x, int y){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << par[i][j] << " \n"[j == 4];
        }
    }
    exit(0);
    if(lvl[x] < lvl[y]) swap(x, y);
    for(int i = H; i >= 0; i--){
        if(lvl[x]-(1 << i) >= lvl[y]){
            x = par[x][i];
        }
    }
    if(x == y) return x;
    for(int i = H; i >= 0; i--){
        if(par[x][i] != par[y][i]){
            x = par[x][i], y = par[y][i];
        }
    }
    return par[x][0];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int u, v;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    cout << "Tree Stored!\nNow you can ask queries\n";
    dfs(1, -1);
    int q;
    cin >> q;
    int x, y;
    while(q--){
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }
    return 0;
}
